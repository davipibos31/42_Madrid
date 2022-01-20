# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dforero- <dforero-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 10:05:21 by alromero          #+#    #+#              #
#    Updated: 2019/09/22 23:30:49 by dforero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.SUFFIXES: .o .c
.c.o:
	$(CC) -c $(CFLAGS) $<


# Macros

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c library.c utilities.c stringutils.c	lib.c
RM = rm -f


# Reglas expl�citas

all: 
	$(CC) $(CFLAGS) -o rush-02 ${SRC}

clean:
	$(RM) rush-02	main
