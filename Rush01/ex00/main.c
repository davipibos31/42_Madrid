/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:17:21 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/09/14 18:27:50 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void);
int		valide_board(char *str);
void	skyscraper(char *str);

int		main(int argc, char *argv[])
{
	int check;

	if (argv[2] != '\0')
		print_error();
	else if (argv[1] == '\0')
		print_error();
	else
	{
		check = valide_board(argv[1]);
		if (check)
			skyscraper(argv[1]);
		else
			print_error();
	}
	return (0);
}
