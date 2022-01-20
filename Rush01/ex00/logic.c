/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:30:36 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/09/15 17:30:06 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
}

int		valide_board(char *str)
{
	int check;
	int i;
	int num;

	check = 1;
	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2)
		{
			if (str[i] != 32)
				check = 0;
		}
		else if (47 < str[i] && str[i] < 53)
		{
			num++;
		}
		i++;
	}
	if (num != 16)
		check = 0;
	return (check);
}
