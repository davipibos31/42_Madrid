/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:05:27 by jgodoy-m          #+#    #+#             */
/*   Updated: 2019/09/07 22:14:24 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	w;
	int h;

	h = 0;
	while (h++ < y)
	{
		w = 0;
		while (w++ < x)
		{
			if ((h == 1 && w == 1) || (w == x && h == y))
				ft_putchar('o');
			else if (((h == y) && (w == 1)) || ((w == x) && (h == 1)))
				ft_putchar('o');
			else if (((w == 1 || w == x)))
				ft_putchar('|');
			else if ((h == 1 || h == y))
				ft_putchar('-');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
