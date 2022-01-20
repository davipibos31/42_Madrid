/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforero- <dforero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:23:51 by dforero-          #+#    #+#             */
/*   Updated: 2019/09/22 22:41:32 by dforero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"
#include "utilities.h"
#include "stringutils.h"

/*
** la función que compara los string
*/

int			ft_strcmp(char *str1, char *str2, int n)
{
	int		i;
	int		diff;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '0') && i < n)
	{
		diff = str1[i] - str2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

/*
** función que calcula el tamaño de un fichero en bytes
*/

int			count_bytes(void)
{
	int		descriptor;
	int		num_bytes;
	char	buffer[2048];
	int		result;

	num_bytes = 0;
	descriptor = open("dict.txt", O_RDONLY);
	result = 1;
	while (result > 0)
	{
		result = read(descriptor, buffer, sizeof(buffer));
		if (result < 0)
		{
			write(1, "Error", 5);
		}
		num_bytes += result;
	}
	close(descriptor);
	return (num_bytes);
}

/*
** para calcular el tamaño de la cadena que nos pasan, solo funciona con números
*/

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		i++;
	return (i);
}
