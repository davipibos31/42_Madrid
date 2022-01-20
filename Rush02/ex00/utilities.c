/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforero- <dforero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:10:03 by dforero-          #+#    #+#             */
/*   Updated: 2019/09/22 23:27:08 by dforero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"
#include "utilities.h"
#include "stringutils.h"

/*
** habría que hacer también alguna función para detectar de forma previa los
** posibles errores del string, como por ejemplo, que tuviese letras"
** con esta función vemos si el string que nos han metido corresponde
** a un número menor o igual a 20
*/

int			less_than_hundred(char *str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = ft_atoi(str);
	if (nbr > 20 && nbr < 100)
		i = 1;
	else if (nbr <= 20 && nbr >= 0)
		i = 2;
	else if (nbr > 20)
		i = 0;
	return (i);
}

/*
** intento de función para rellenar de ceros la cadena e intentar
** hacerlo de manera recursiva ... no hacedle mucho caso, es una prueba
*/

char		*cero(char *str)
{
	int		i;
	int		len;

	i = 1;
	len = ft_strlen(str);
	while (i < len)
	{
		str[0] = '1';
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
** esta es la función que en principio debería hacer todo lo que hace el main,
** solo que por ahora está incompleta
*/

char		*cadena(char *str)
{
	int		descriptor;
	char	*retorno;

	retorno = NULL;
	descriptor = open("dict.txt", O_RDWR, S_IRUSR);
	if (descriptor == 1)
		write(1, "Dict Error\n", 11);
	read(descriptor, retorno, ft_strlen(str));
	close(descriptor);
	return (retorno);
}

/*
** función con la que pretendo convertir números en arrays
*/

char		**arrays(char *str)
{
	int		i;
	int		digit;
	int		nbr;
	char	**numbers;
	int		k;

	numbers = malloc(sizeof(char*) * 20);
	nbr = ft_atoi(str);
	digit = calculate_digits(nbr);
	k = 1;
	while (nbr > 9)
	{
		i = nbr;
		nbr = nbr / 10;
		*numbers[0] = i + 48;
		*(numbers[0] + k) = 0 + 48;
		i = nbr % 10;
		*numbers[1] = i + 48;
	}
	return (numbers);
	free(numbers);
}

/*
** Handle errors
*/

int			error(long double nbr)
{
	int flag;

	flag = 1;
	if (nbr < 0)
		flag = 0;
	else
		flag = 1;
	return (flag);
}
