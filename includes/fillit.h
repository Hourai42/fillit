/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:04:25 by ttran             #+#    #+#             */
/*   Updated: 2017/12/17 20:03:16 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
/*Misc Functions */
void	ft_putstr(char *str);

/*Parse file */
typedef struct	s_tetri
{
	char	**tetrimino;
	struct s_tetri *next;
	int 	minx;
	int		miny;
	int		maxx;
	int		maxy;
	char 	place;
}	t_tetri;
int		ft_listcreate(t_tetri **p, char *str, int br);
char	**ft_convertdata(char *str, int br, t_tetri *fuck);
t_tetri *parsefile(char *file);
void	print_pieces(t_tetri *pieces);
void	ft_free(t_tetri *tetri);

/*Check input */
int	open_error(int fd);
int	close_error(int fd);
int	ft_check_buffer(char *str,int br);
int	ft_check_characters(char *str);
int	ft_check_connections(char **str, int y, int x);
void	ft_min(t_tetri *fuck, int y, int x, int pound);
void	ft_max(t_tetri *fuck, int y, int x, int pound);
int	check_valid(t_tetri *fuck, char **store);

#endif
