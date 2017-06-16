/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <calgrizz52@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:33:09 by mkok              #+#    #+#             */
/*   Updated: 2017/05/31 14:13:54 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int argc, char **argv)
{
	t_g_prop	*g;

	if (display_usage(argc))
		return (0);
	if (atoi(argv[1]) < 24 || atoi(argv[2]) < 24 ||
		atoi(argv[1]) > 500 || atoi(argv[2]) > 500)
	{
		ft_putstr("ALL VALUES MUST BE GREATER THAN OR EQUAL TO 24\n");
		ft_putstr("AND LESS THAN OR EQUAL TO 500\n");
		return (0);
	}
	g = init_t_g_prop();
	(*g).map_w = atoi(argv[1]);
	(*g).map_h = atoi(argv[2]);
	make_map(g);
	wolf_key_funct(KEY_LEFT, g);
	make_maze(g);
	render_screen(g);
	draw_x(g);
	mlx_mouse_hook((*g).win, wolf_mouse_hook, g);
	mlx_hook((*g).win, KEY_PRESS, KEY_PRESS_MASK, wolf_key_funct, g);
	mlx_loop_hook((*g).mlx, render_screen, g);
	mlx_loop((*g).mlx);
	return (0);
}

int		display_usage(int count)
{
	if (count != 3)
	{
		ft_putstr("Usage: ./wolf3d (map_width) (map_height)\n");
		ft_putstr("	int map_width:  width of new map to be generated\n");
		ft_putstr("	int	map_height: height of new map to be generated\n\n");
		return (1);
	}
	else
		return (0);
}

void	draw_border(t_g_prop *g)
{
	(*g).value = 1;
	fill_row(0, (*g).map_w, 0, g);
	(*g).value = 2;
	fill_row(0, (*g).map_w, (*g).map_h - 1, g);
	(*g).value = 3;
	fill_column(1, (*g).map_h - 1, 0, g);
	(*g).value = 4;
	fill_column(1, (*g).map_h - 1, (*g).map_w - 1, g);
}
