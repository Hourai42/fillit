/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:42:49 by ttran             #+#    #+#             */
/*   Updated: 2017/12/14 18:30:41 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	t_tetri *tetri;

	if (argc == 2)
	{
		tetri = parsefile(argv[1]); 
		print_pieces(tetri);
		ft_free(tetri);
	}
	else
	{
		ft_putstr("Enter only one file with 1 through 26 Tetriminos, each separated by a newline.");	
		return (1);
	}
	return (0);
}
