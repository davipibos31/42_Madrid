/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuadros.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 09:56:17 by fjimenez          #+#    #+#             */
/*   Updated: 2019/09/25 23:16:55 by dlares           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Este codigo ha sido creado por la colaboracion de un gran grupo.
//como ha sido sugerido.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		todo(char *argv, int argc);

int		main(int argc, char **argv)
{
	int				a;
	int				fp;
	char			buf[10000];
	unsigned long	i;
	char			texto;

	i = 0;
	a = 1;
	while (i < sizeof(buf))
	{
		buf[i] = '\0';
		i++;
	}
	if (argc == 1)
	{
		fp = open(STDIN_FILENO, O_RDWR | O_CREAT);
		read(0, buf, sizeof(buf));
		write(fp, &buf, sizeof(buf));
		close(fp);
		fp = open("tablaman.txt", O_RDWR | O_CREAT);
		if (fp != -1)
		{
			i = 0;
			while (buf[i] != '\0')
			{
				texto = buf[i];
				write(fp, &texto, 1);
				i++;
			}
		}
		todo(*argv, argc);
	}
	else
	{
		while (a < argc)
		{
			todo(argv[a], argc);
			a++;
		}
	}
}

int		todo(char *argv, int argc)
{
	int		i;
	int		j;
	int		cont;
	int		k;
	char	texto;
	char	*file;
	int		fp;
	int		colum;
	int		filas;
	char	**plantilla;
	char	titulo[10];
	char	dibujo;
	char	objeto;
	char	vacio;
	int		x_mayor;
	int		y_mayor;
	int		verdad;
	char	mayor;
	char	menor;
	int		cont_saltos;
	int		q;
	int		t;
	int		contador;
	int		mayoraux;

	j = 0;
	i = 0;
	colum = 0;
	filas = 0;
	file = NULL;
	cont_saltos = 0;
	if (argc == 1)
	{
		fp = open("tablaman.txt", O_RDONLY);
	}
	else
	{
		fp = open(argv, O_RDONLY);
	}
	if (fp != -1)
	{
		while (read(fp, &texto, 1))
			i++;
		close(fp);
		file = (char*)malloc(sizeof(char) * i);
		if (file == NULL)
		{
			free(file);
			file = NULL;
			return (0);
		}
		if (argc == 1)
		{
			fp = open("tablaman.txt", O_RDONLY);
		}
		else
		{
			fp = open(argv, O_RDONLY);
		}
		i = 0;
		if (fp == -1)
		{
			write(1, "map error\n", 11);
			free(file);
			file = NULL;
			return (0);
		}
		while (read(fp, &texto, 1))
		{
			file[i] = texto;
			i++;
		}
		close(fp);
	}
	else
	{
		write(1, "map error\n", 11);
		free(file);
		file = NULL;
		return (0);
	}
	i = 0;
	cont = 0;
	while (file[i] != '\n')
	{
		titulo[i] = file[i];
		i++;
	}
	cont = i;
	titulo[i] = '\0';
	dibujo = titulo[i - 1];
	objeto = titulo[i - 2];
	vacio = titulo[i - 3];
	i = 0;
	if (dibujo == objeto || dibujo == vacio || objeto == vacio)
	{
		write(1, "map error\n", 11);
		free(file);
		file = NULL;
		return (0);
	}
	i = cont + 1;
	while (file[i] != '\0')
	{
		if (file[i] == vacio || file[i] == objeto || file[i] == '\n')
		{
			j = 0;
		}
		else
		{
			write(1, "map error\n", 11);
			free(file);
			file = NULL;
			return (0);
		}
		i++;
	}
	i = cont + 1;
	j = 0;
	k = 0;
	while (file[i] != '\n')
	{
		i++;
		j++;
	}
	i = cont + 1;
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
		{
			cont_saltos++;
			if (j != k)
			{
				write(1, "map error\n", 11);
				free(file);
				file = NULL;
				return (0);
			}
			k = 0;
		}
		else if ((file[i] != '\n'))
			k++;
		i++;
	}
	i = cont + 1;
	j = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
		{
			j++;
			filas = j;
		}
		else if ((file[i] != '\n') && (j < 1))
		{
			k++;
			colum = k;
		}
		i++;
	}
	if (cont_saltos != filas)
	{
		write(1, "map error\n", 10);
		free(file);
		file = NULL;
		return (0);
	}
	if (filas < 1 || colum < 1)
	{
		write(1, "map error\n", 10);
		free(file);
		file = NULL;
		return (0);
	}
	plantilla = (char**)malloc(sizeof(char*) * filas - 1);
	if (plantilla == NULL)
	{
		free(plantilla);
		return (0);
	}
	i = 0;
	while (i < filas)
	{
		plantilla[i] = (char*)malloc(sizeof(char) * colum);
		if (plantilla[i] == NULL)
		{
			free(plantilla[i]);
			return (0);
		}
		i++;
	}
	i = 0;
	j = 0;
	k = cont + 1;
	while (file[k] != '\0')
	{
		i = 0;
		while (i < colum)
		{
			plantilla[j][i] = file[k];
			k++;
			i++;
		}
		j++;
		k++;
	}
	free(file);
	file = NULL;
	i = 0;
	while (i < filas)
	{
		j = 0;
		while (j < colum)
		{
			if (plantilla[i][j] == objeto)
				plantilla[i][j] = '0';
			else if (plantilla[i][j] == vacio)
				plantilla[i][j] = '1';
			j++;
		}
		i++;
	}
	i = 1;
	while (i < filas)
	{
		j = 1;
		while (j < colum)
		{
			if (plantilla[i][j] == '1')
			{
				menor = plantilla[i - 1][j];
				if (plantilla[i - 1][j - 1] < menor)
					menor = plantilla[i - 1][j - 1];
				if (plantilla[i][j - 1] < menor)
					menor = plantilla[i][j - 1];
				plantilla[i][j] = plantilla[i][j] + menor - '0';
			}
			j++;
		}
		i++;
	}
	i = 0;
	mayor = plantilla[0][0];
	while (i < filas)
	{
		j = 0;
		while (j < colum)
		{
			if (plantilla[i][j] > mayor)
				mayor = plantilla[i][j];
			j++;
		}
		i++;
	}
	verdad = 1;
	i = 0;
	while (i < filas && verdad == 1)
	{
		j = 0;
		while (j < colum && verdad == 1)
		{
			if (plantilla[i][j] == mayor)
			{
				x_mayor = j;
				y_mayor = i;
				verdad = 0;
			}
			j++;
		}
		i++;
	}
	j = 0;
	while (titulo[j] != '\0')
	{
		write(1, &titulo[j], 1);
		j++;
	}
	write(1, "\n", 1);
	t = x_mayor;
	mayoraux = mayor - '0';
	contador = mayoraux;
	q = mayoraux;
	while (contador > 0)
	{
		mayoraux = q;
		x_mayor = t;
		plantilla[y_mayor][x_mayor] = dibujo;
		while (mayoraux > 0)
		{
			plantilla[y_mayor][x_mayor] = dibujo;
			x_mayor--;
			mayoraux--;
		}
		y_mayor--;
		contador--;
	}
	i = 0;
	j = 0;
	while (i < filas)
	{
		j = 0;
		while (j < colum)
		{
			if (plantilla[i][j] == '0')
				plantilla[i][j] = objeto;
			else if (plantilla[i][j] != dibujo)
				plantilla[i][j] = vacio;
			write(1, &plantilla[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	if (*plantilla != NULL)
	{
		free(*plantilla);
		*plantilla = NULL;
	}
	free(plantilla);
	plantilla = NULL;
	write(1, "\n", 1);
	return (0);
}
