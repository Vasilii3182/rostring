/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:54:30 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/30 16:30:30 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int len;
	
	len = 0;
	while (str[len] != '\0')
	{
		len ++;
	}
	return (len);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_count_word(char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) == 0)
		{
			nb++;
			while (ft_isspace(str[i]) == 0 && str[i] != '\0')
				i++;
		}
		while (ft_isspace(str[i]) == 1 && str[i] != '\0')
			i++;
	}
	return (nb);
}

int		ft_len_shortened(char *str, int len)
{
	int i;
	int start;
	int end;
	
	i = 0;
	start = 0;
	end = 0;
	while (ft_isspace(str[i]) == 1)
    {   
		start++;	
		i++;
	}
	i = len - 1;
	while (ft_isspace(str[i]) == 1)
	{
		end++;
		i--;
	}
	return (len - start - end);
}

int		get_to_word(char *str, int word)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
        i++;
    while (str[i] != '\0')
    {
        if (ft_isspace(str[i]) == 0)
        {
            nb++;
			if (nb == word)
				return (i);
            while (ft_isspace(str[i]) == 0 && str[i] != '\0')
                i++;
        }
        while (ft_isspace(str[i]) == 1 && str[i] != '\0')
            i++;
    }
	return (i);
}

int		main(int argc, char **argv)
{
	int len;
	char *new;
	int	new_len;
	int f_word;
	int i;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	len = ft_strlen(argv[1]);
	new_len = ft_len_shortened(argv[1], len);
	printf("new_len = %d\n", new_len);
	if ((new = (char*)malloc(sizeof(char) * (new_len + 1))) == NULL)
		return (-1);
	new[new_len] = '\0';
	f_word = get_to_word(argv[1], 2);
	i = 0;
	while (i < new_len)
	{
		new[i] = argv[1][f_word];
		i++;
		f_word++;
	}
	printf("%s\n", new);
	return (0);
}
