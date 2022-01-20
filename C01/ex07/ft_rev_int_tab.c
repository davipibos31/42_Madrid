/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:31:45 by dpinuel-          #+#    #+#             */
/*   Updated: 2019/09/16 17:34:32 by dpinuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int c;

	n = 0;
	while (size - 1 > n)
	{
		c = tab[n];
		tab[n] = tab[size - 1];
		tab[size - 1] = c;
		n++;
		size--;
	}
}
