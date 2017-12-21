/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:04:25 by ttran             #+#    #+#             */
/*   Updated: 2017/12/20 18:38:51 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define COUNTER_VARIABLES int y = 0; int x = 0;
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
/*Misc Functions */
void	ft_putstr(char *str);
void	ft_putchar(char c);

/*Parse file */
typedef struct	s_tetri
{
	char	**tetrimino;
	struct s_tetri *next;
	int 	minx;
	int		miny;
	int		maxx;
	int		maxy;
	char 	letter;
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
int	ft_setletter(t_tetri *fuck);
extern int globalcheck;

/*Solve */
int	smallest_square(int i);
void	createboard(t_tetri *tetri);
void printboard(char **board, int dimensions);
extern int dimensions;
int	solvefillit(t_tetri *tetri, char **board, int dimensions);
void	deletepiece(int ps[4][2], char **board);
void	placepiece(int ps[4][2], char **board, t_tetri *tetri);
int		canplace(int c[4][2], char **board, int y, int x, int ps[4][2]);
void	finishboard(int c[4][2], int y, int x, int ps[4][2]);
void	zeroboard(int c[4][2]);
void	tetricoordinates(int c[4][2], t_tetri *tetri);
#endif
