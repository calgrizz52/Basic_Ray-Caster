/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <calgrizz52@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:40:31 by mkok              #+#    #+#             */
/*   Updated: 2017/05/31 12:10:35 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	make_map(t_g_prop *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (((*g).map = (int**)malloc(sizeof(int*) * (*g).map_h)))
	{
		while (j < (*g).map_h)
		{
			(*g).map[j] = (int*)malloc(sizeof(int) * (*g).map_w);
			while (i < (*g).map_w)
			{
				(*g).map[j][i] = 0;
				i++;
			}
			i = 0;
			j++;
		}
		j = 0;
	}
	draw_border(g);
}

void	print_map(t_g_prop *g)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < (*g).map_h)
	{
		while (x < (*g).map_w)
		{
			ft_putnbr((*g).map[y][x]);
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

void	fill_row(int x0, int x1, int row, t_g_prop *g)
{
	int		x;

	x = x0;
	while (x0 != x1)
	{
		(*g).map[row][x0] = (*g).value;
		x0++;
	}
}

void	fill_column(int y0, int y1, int col, t_g_prop *g)
{
	while (y0 != y1)
	{
		(*g).map[y0][col] = (*g).value;
		y0++;
	}
}

void	make_maze(t_g_prop *g)
{
	(*g).map[22][8] = 5;
	(*g).value = 2;
	fill_row(10, 14, 23, g);
	fill_row(5, 20, 10, g);
	fill_row(7, 10, 15, g);
	(*g).value = 1;
	fill_column(12, 24, 13, g);
	fill_column(12, 24, 10, g);
	(*g).value = 3;
	fill_row(5, 10, 20, g);
	fill_row(14, 20, 12, g);
	(*g).value = 4;
	fill_column(10, 20, 5, g);
}
