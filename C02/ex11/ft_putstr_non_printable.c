/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:39:37 by dpinuel-          #+#    #+#             */
/*   Updated: 2019/09/19 14:42:28 by dpinuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_hex(int np)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (np > 16)
	{
		print_hex(np / 10);
		print_hex(np % 10);
	}
	else
		ft_putchar(hex[np]);
}

void		ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] <= 31 && str[i] >= 0) || str[i] == 127)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			print_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i += 1;
	}
}
