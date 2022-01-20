/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringutils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforero- <dforero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:21:42 by dforero-          #+#    #+#             */
/*   Updated: 2019/09/22 23:18:13 by dforero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGUTILS_H
# define STRINGUTILS_H

# include "utilities.h"
# include "library.h"

int		ft_strcmp(char *str1, char *str2, int n);
void	ft_putchar(char c);
int		count_bytes(void);
int		ft_strlen(char *str);

#endif
