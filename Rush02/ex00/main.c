/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforero- <dforero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 10:23:04 by alromero          #+#    #+#             */
/*   Updated: 2019/09/22 23:35:12 by dforero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int				main(int argc, char **argv)
{
	int			i;
	int			err;

	err = 0;
	i = 0;
	if (argc == 2)
	{
		print_numbers(argv[1], "dict.txt");
	}
	if (argc == 3)
	{
		if (*argv[2] >= '0' && *argv[2] <= '9')
			print_numbers(argv[2], argv[1]);
		else
			err = 1;
	}
	if (err == 1)
		write(1, "Error\n", 6);
	return (0);
}
