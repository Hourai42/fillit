/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:04:25 by ttran             #+#    #+#             */
/*   Updated: 2017/12/14 18:43:08 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_tetri
{
	char	**tetrimino;
	struct s_tetri *next;
}	t_tetri;

void	ft_putstr(char *str);
void	ft_listcreate(t_tetri **p, char *str);
char	**ft_convertdata(char *str);
t_tetri *parsefile(char *file);
void	print_pieces(t_tetri *pieces);
void	ft_free(t_tetri *tetri);
#endif
