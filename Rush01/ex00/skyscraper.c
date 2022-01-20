/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycraper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:25:43 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/09/15 19:17:15 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	write_board(int *str)
{
	int *board;
	int i;
	int j;

	board = (int *)malloc(16 * sizeof(int));
	pos = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			*(board + (i * 4) + j) = '*';
			write(1, &*(board + (i * 4) + j), 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	free(board);
}

void	skyscraper(char *str)
{
	int		i;
	int		j;
	int		box[16];

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != 32)
		{
			box[j] = str[i];
			j++;
		}
		i++;
	}
	box[j] = '\0';
	write_board(box);
}
