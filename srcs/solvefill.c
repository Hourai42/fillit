/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:00:03 by ttran             #+#    #+#             */
/*   Updated: 2017/12/20 23:17:38 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //Delete this along with all da putstrs later! 

int dimensions = 0;
int tally = 0;

int	solvefillit(t_tetri *tetri, char **board, int dimensions)
{
	int y;
	int x;
	int	 c[4][2] = {{0, 0},
					{0, 0},
					{0, 0},
					{0, 0}};
	int  ps[4][2] = {{0, 0},
					{0, 0},
					{0, 0},
					{0, 0}};
	y = 0;
	x = 0;
	if (tetri == NULL)
		return (1); 
	tetricoordinates(c, tetri);
	while (y < dimensions)
	{
		while (x < dimensions)
		{
			if (board[y][x] == '.')
				if (canplace(c, board, y, x, ps) == 1)
				{
					placepiece(ps, board, tetri);
					if (solvefillit(tetri->next, board, dimensions) == 1)
						return (1);
					deletepiece(ps, board);
				}				
			x++;
		}
		x = 0;
		y++;
	}
	if (tetri->letter == 'A')
	{
		tally++;
		solvefillit(tetri, board, dimensions + 1);	
	}
	else
		return (0);
	return (1);
}

void	deletepiece(int ps[4][2], char **board)
{
	board[ps[0][0]][ps[0][1]] = '.';
	board[ps[1][0]][ps[1][1]] = '.';
	board[ps[2][0]][ps[2][1]] = '.';
	board[ps[3][0]][ps[3][1]] = '.';
}

void	placepiece(int ps[4][2], char **board, t_tetri *tetri)
{
	char AZ;

	AZ = tetri->letter;
	board[ps[0][0]][ps[0][1]] = AZ;
	board[ps[1][0]][ps[1][1]] = AZ;
	board[ps[2][0]][ps[2][1]] = AZ;
	board[ps[3][0]][ps[3][1]] = AZ;
}

int		canplace(int c[4][2], char **board, int y, int x, int ps[4][2])
{
	if (y + c[0][0] < 0 || y + c[0][0] >= dimensions || x + c[0][1] < 0 || x + c[0][1] >= dimensions)
		return (0);
	if (board[y + c[0][0]][x + c[0][1]] != '.')
		return (0);
	if (y + c[1][0] < 0 || y + c[1][0] >= dimensions || x + c[1][1] < 0 || x + c[1][1] >= dimensions)
		return (0);
	if (board[y + c[1][0]][x + c[1][1]] != '.')
		return (0);
	if (y + c[2][0] < 0 || y + c[2][0] >= dimensions || x + c[2][1] < 0 || x + c[2][1] >= dimensions)
		return (0);
	if (board[y + c[2][0]][x + c[2][1]] != '.')
		return (0);
	if (y + c[3][0] < 0 || y + c[3][0] >= dimensions || x + c[3][1] < 0 || x + c[3][1] >= dimensions)
		return (0);
	if (board[y + c[3][0]][x + c[3][1]] != '.')
		return (0);
	finishboard(c, y, x, ps);
	return (1);
}

void	finishboard(int c[4][2], int y, int x, int ps[4][2])
{
	ps[0][0] = y; 
	ps[0][1] = x;
	ps[1][0] = y + c[1][0]; 
	ps[1][1] = x + c[1][1];
	ps[2][0] = y + c[2][0];
	ps[2][1] = x + c[2][1];
	ps[3][0] = y + c[3][0];
	ps[3][1] = x + c[3][1];
}

void	zeroboard(int c[4][2])
{
	int minusy;
	int minusx;

	minusy = c[0][0];
	minusx = c[0][1];
	c[0][0] = c[0][0] - minusy;
	c[0][1] = c[0][1] - minusx;
	c[1][0] = c[1][0] - minusy;
	c[1][1] = c[1][1] - minusx;
	c[2][0] = c[2][0] - minusy;
	c[2][1] = c[2][1] - minusx;
	c[3][0] = c[3][0] - minusy;
	c[3][1] = c[3][1] - minusx;
}

void	tetricoordinates(int c[4][2], t_tetri *tetri)
{
	int my;
	int mx;
	int i;
	
	i = 0;
	my = tetri->miny;
	mx = tetri->minx;
	while (my <= tetri->maxy)
	{
		while (mx <= tetri->maxx)
		{
			if (tetri->tetrimino[my][mx] == '#')
			{
				c[i][0] = my;
				c[i][1] = mx;	
				i++;
			}
			mx++;	
		}
		mx = tetri->minx;
		my++;
	}
	zeroboard(c);
}

int		smallest_square(int i)
{	
	if (i == 1)
		return (2);
	else if (i == 2)
		return (3);
	else if (i == 3 || i == 4)
		return (4);
	else if (i > 4 && i < 7)
		return (5);
	else if (i > 6 && i < 10)
		return (6);
	else if (i > 9 && i < 13)
		return (7);
	else if (i > 12 && i < 17)
		return (8);
	else if (i > 16 && i < 21)
		return (9);
	else if (i > 20)
		return (10);
	else 
		return (0);
}

void	createboard(t_tetri *tetri)
{
	char **board;	
	int i;
	int n;

	n = 0;
	i = 0;
	board = (char **)malloc(sizeof(char *) * (120 + 1));
	board[120] = 0;
	while (i < 120)
	{
		board[i] = (char *)malloc(sizeof(char) * (120 + 1));	
		board[i++][120] = '\0';
	}
	i = 0;
	while (n < 120)
	{
		while (i < 120)
			board[n][i++] = '.';	
		i = 0;
		n++;
	}
	dimensions = smallest_square(globalcheck + 1);
   	if ((solvefillit(tetri, board, dimensions) == 1) || (solvefillit(tetri, board, dimensions) == 0))	
		printboard(board, dimensions);
}

void	printboard(char **board, int dimensions)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (n < dimensions + tally)
	{
		while (i < dimensions + tally)
			ft_putchar(board[n][i++]);	
		i = 0;
		write(1, "\n", 1);
		n++;
	}
}
