/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <calgrizz52@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:17:52 by mkok              #+#    #+#             */
/*   Updated: 2017/05/31 12:10:56 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_up(t_g_prop *g)
{
	if ((*g).map[(int)((*(*g).d).pos_x + (*(*g).d).dir_x *
			(*(*g).d).movespeed)][(int)((*(*g).d).pos_y)] == 0)
		(*(*g).d).pos_x += (*(*g).d).dir_x * (*(*g).d).movespeed;
	if ((*g).map[(int)((*(*g).d).pos_x)][(int)((*(*g).d).pos_y +
			(*(*g).d).dir_y * (*(*g).d).movespeed)] == 0)
		(*(*g).d).pos_y += (*(*g).d).dir_y * (*(*g).d).movespeed;
	clear_screen(g);
}

void	move_down(t_g_prop *g)
{
	if ((*g).map[(int)((*(*g).d).pos_x - (*(*g).d).dir_x *
			(*(*g).d).movespeed)][(int)((*(*g).d).pos_y)] == 0)
		(*(*g).d).pos_x -= (*(*g).d).dir_x * (*(*g).d).movespeed;
	if ((*g).map[(int)((*(*g).d).pos_x)][(int)((*(*g).d).pos_y -
			(*(*g).d).dir_y * (*(*g).d).movespeed)] == 0)
		(*(*g).d).pos_y -= (*(*g).d).dir_y * (*(*g).d).movespeed;
	clear_screen(g);
}

void	move_right(t_g_prop *g)
{
	(*(*g).d).old_dir_x = (*(*g).d).dir_x;
	(*(*g).d).dir_x = (*(*g).d).dir_x * cos(-(*(*g).d).rotspeed) -
		(*(*g).d).dir_y * sin(-(*(*g).d).rotspeed);
	(*(*g).d).dir_y = (*(*g).d).old_dir_x * sin(-(*(*g).d).rotspeed) +
		(*(*g).d).dir_y * cos(-(*(*g).d).rotspeed);
	(*(*g).d).old_plane_x = (*(*g).d).plane_x;
	(*(*g).d).plane_x = (*(*g).d).plane_x * cos(-(*(*g).d).rotspeed) -
		(*(*g).d).plane_y * sin(-(*(*g).d).rotspeed);
	(*(*g).d).plane_y = (*(*g).d).old_plane_x * sin(-(*(*g).d).rotspeed) +
		(*(*g).d).plane_y * cos(-(*(*g).d).rotspeed);
	clear_screen(g);
}

void	move_left(t_g_prop *g)
{
	(*(*g).d).old_dir_x = (*(*g).d).dir_x;
	(*(*g).d).dir_x = (*(*g).d).dir_x * cos((*(*g).d).rotspeed) -
		(*(*g).d).dir_y * sin((*(*g).d).rotspeed);
	(*(*g).d).dir_y = (*(*g).d).old_dir_x * sin((*(*g).d).rotspeed) +
		(*(*g).d).dir_y * cos((*(*g).d).rotspeed);
	(*(*g).d).old_plane_x = (*(*g).d).plane_x;
	(*(*g).d).plane_x = (*(*g).d).plane_x * cos((*(*g).d).rotspeed) -
		(*(*g).d).plane_y * sin((*(*g).d).rotspeed);
	(*(*g).d).plane_y = (*(*g).d).old_plane_x * sin((*(*g).d).rotspeed) +
		(*(*g).d).plane_y * cos((*(*g).d).rotspeed);
	clear_screen(g);
}
