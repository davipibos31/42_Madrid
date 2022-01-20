/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforero- <dforero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 00:43:38 by dforero-          #+#    #+#             */
/*   Updated: 2019/09/22 23:28:51 by dforero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "stringutils.h"
#include "lib.h"

/*
** esta es la función que se encarga de imprimir solo lo que hay después de ':'
*/

void		strdetc(char *str)
{
	int		i;

	i = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	while (str[i] <= 126 && str[i] >= 32)
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*
** calculate the digits of a number
*/

int			calculate_digits(unsigned long long num)
{
	int		digits;

	digits = 0;
	while (num != 0)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

/*
** Print numbers
*/

int			print_numbers(char *str, char *txt)
{
	int		i;
	char	*buf;
	int		cmp;

	i = 0;
	cmp = 0;
	buf = open_file(txt);
	while (buf[i] != '\0')
	{
		if (ft_strcmp(&buf[i], str, ft_strlen(str)) == 0)
		{
			strdetc(&buf[i]);
			write(1, "\n", 1);
			cmp = 1;
			break ;
		}
		i++;
	}
	if (cmp == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (0);
}

/*
** ATOI
*/

int			ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		mult;

	i = 0;
	sign = 1;
	mult = 0;
	while ((str[i] == ' ') || (str[i] <= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		mult = mult * 10 + str[i] - 48;
		i++;
	}
	return (mult * sign);
}

char		*open_file(char *txt)
{
	int		fd;
	int		size_file;
	char	*buf;

	size_file = count_bytes();
	buf = malloc(sizeof(char) * size_file);
	if (txt == NULL)
		fd = open("dict.txt", O_RDONLY);
	else
		fd = open(txt, O_RDONLY);
	read(fd, buf, size_file);
	buf[size_file] = '\0';
	if (fd == -1)
		write(1, "Error", 5);
	return (buf);
}
