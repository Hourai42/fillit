/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:08:36 by ttran             #+#    #+#             */
/*   Updated: 2017/12/14 20:42:11 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_listcreate(t_tetri **p, char *str)
{
	t_tetri	 *new;

	new = malloc(sizeof(t_tetri));
	new->next = NULL;
	new->tetrimino = ft_convertdata(str);
	(*p)->next = new;
	(*p) = new;
}

char	**ft_convertdata(char *str)
{
	int 	i;
	char	**store;
	int 	n;

	n = 0;
	store = (char **)malloc(sizeof(char *) * 5);
	while (n < 4)
		store[n++] = (char *)malloc(sizeof(char) * 5);
	store[4] = (char *)malloc(sizeof(char));
	n = 0;
	str[20] = '\0';
	while (*str)
	{
		i = 0;
		while (*str != '\n' && *str != '\0') 
			store[n][i++] = *str++;
		store[n++][i] = '\0';
		str++;
	}
	return (store);
}

t_tetri	*parsefile(char *file)
{
	int 	fd;
	char	str[21];
	int		br;
	t_tetri	*list;
	t_tetri 	*p;
	
	fd = open(file, O_RDONLY);
	list = malloc(sizeof(t_tetri));
	list->tetrimino = NULL;
	p = list;
	while ((br = read(fd, str, 21)) >= 20)
	{
		if (list->tetrimino == NULL)
			list->tetrimino = ft_convertdata(str);
		else
			ft_listcreate(&p, str);
	}
	close(fd);
	return (list);
}

void	print_pieces(t_tetri *pieces)
{
	t_tetri *p;
	int n;

	n = 0;
	p = pieces;
	while (p != NULL)
	{
		while (p->tetrimino[n] != '\0')
		{
			ft_putstr(p->tetrimino[n++]);;
			write(1, "\n", 1);
		}
		n = 0;
		p = p->next;
	}
}

void	ft_free(t_tetri *tetri)
{
	t_tetri	*p;

	while (tetri != NULL)
	{
		p = tetri;
		tetri = tetri->next;
		p->tetrimino = 0;
		p->next = NULL;
		free(p);	
	}
}







