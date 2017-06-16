/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <calgrizz52@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:46:55 by mkok              #+#    #+#             */
/*   Updated: 2017/05/31 12:12:01 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_g_prop	*init_t_g_prop(void)
{
	t_g_prop	*g;
	double		shit;

	shit = 0.15;
	if (!((g) = (t_g_prop*)malloc(sizeof(t_g_prop))))
	{
		ft_putstr("Could not malloc g\n");
		return (NULL);
	}
	if (!((*g).mlx = mlx_init()))
	{
		ft_putstr("Could not malloc mlx\n");
		return (NULL);
	}
	if (!((*g).win = mlx_new_window((*g).mlx, WIN_W, WIN_H, "POOP CITY")))
	{
		ft_putstr("Could not malloc window\n");
		return (NULL);
	}
	if (!((*g).d = (t_d_prop*)malloc(sizeof(t_d_prop))))
		return (NULL);
	init_t_g_prop_help(g, shit);
	return (g);
}

void		init_t_g_prop_help(t_g_prop *g, double shit)
{
	(*(*g).d).poop = 0;
	(*(*g).d).pos_x = 22;
	(*(*g).d).pos_y = 12;
	(*(*g).d).dir_x = -1;
	(*(*g).d).dir_y = 0;
	(*(*g).d).plane_x = 0;
	(*(*g).d).plane_y = 0.66;
	(*(*g).d).movespeed = shit * 5.0;
	(*(*g).d).rotspeed = shit * 3.0;
}
