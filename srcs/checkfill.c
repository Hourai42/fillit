/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:49:04 by ttran             #+#    #+#             */
/*   Updated: 2017/12/16 14:15:18 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	open_error(int fd)
{
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (0);
	}
	return (1);
}

int	close_error(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("close() error\n");
		return (0);
	}
	return (1);
}

int ft_check_buffer(char *str, int br)
{

	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	if (br == 21)
		if (str[20] != '\n')
			return (0);
	if (ft_check_characters(str) == 0)
		return (0);
	return (1);	
}

int	ft_check_characters(char *str)
{
	int i;
	int n;
	int count;

	count = 0;
	n = 4;
	i = 0;
	while (n < 21)
	{
		while (i < n)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			if (str[i] == '#')
				count++;
			i++;
		}
		i++;
		n += 5;
	}
	if (count != 4)
		return (0);
	return (1);
}
