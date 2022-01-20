/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforero- <dforero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 00:40:14 by dforero-          #+#    #+#             */
/*   Updated: 2019/09/22 23:26:36 by dforero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "utilities.h"
# include "stringutils.h"
# include "lib.h"

int		print_numbers(char *str, char *txt);
int		calculate_digits(unsigned long long num);
int		ft_atoi(char *str);
void	strdetc(char *str);
char	*open_file(char *str);

#endif
