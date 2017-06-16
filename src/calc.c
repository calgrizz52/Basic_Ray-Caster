/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <calgrizz52@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:46:06 by mkok              #+#    #+#             */
/*   Updated: 2017/05/31 12:09:18 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calc_rpos_and_rdir(t_g_prop *g)
{
	(*(*g).d).camera_x = ((2 * ((*(*g).d).poop)) / ((double)WIN_W) - 1);
	(*(*g).d).ray_pos_x = (*(*g).d).pos_x;
	(*(*g).d).ray_pos_y = (*(*g).d).pos_y;
	(*(*g).d).ray_dir_x = (*(*g).d).dir_x +
		(*(*g).d).plane_x * (*(*g).d).camera_x;
	(*(*g).d).ray_dir_y = (*(*g).d).dir_y +
		(*(*g).d).plane_y * (*(*g).d).camera_x;
	(*(*g).d).map_x = (int)(*(*g).d).ray_pos_x;
	(*(*g).d).map_y = (int)(*(*g).d).ray_pos_y;
	(*(*g).d).delta_dist_x = sqrt(1 + ((*(*g).d).ray_dir_y *
		(*(*g).d).ray_dir_y) / ((*(*g).d).ray_dir_x * (*(*g).d).ray_dir_x));
	(*(*g).d).delta_dist_y = sqrt(1 + ((*(*g).d).ray_dir_x *
		(*(*g).d).ray_dir_x) / ((*(*g).d).ray_dir_y * (*(*g).d).ray_dir_y));
	(*(*g).d).hit = 0;
}

void	calc_step_and_side_dist(t_g_prop *g)
{
	if ((*(*g).d).ray_dir_x < 0)
	{
		(*(*g).d).step_x = -1;
		(*(*g).d).side_dist_x = ((*(*g).d).ray_pos_x -
			(*(*g).d).map_x) * (*(*g).d).delta_dist_x;
	}
	else
	{
		(*(*g).d).step_x = 1;
		(*(*g).d).side_dist_x = ((*(*g).d).map_x + 1.0 -
			(*(*g).d).ray_pos_x) * (*(*g).d).delta_dist_x;
	}
	if ((*(*g).d).ray_dir_y < 0)
	{
		(*(*g).d).step_y = -1;
		(*(*g).d).side_dist_y = ((*(*g).d).ray_pos_y -
			(*(*g).d).map_y) * (*(*g).d).delta_dist_y;
	}
	else
	{
		(*(*g).d).step_y = 1;
		(*(*g).d).side_dist_y = ((*(*g).d).map_y + 1.0 -
			(*(*g).d).ray_pos_y) * (*(*g).d).delta_dist_y;
	}
}

void	perform_dda(t_g_prop *g)
{
	while ((*(*g).d).hit == 0)
	{
		if ((*(*g).d).side_dist_x < (*(*g).d).side_dist_y)
		{
			(*(*g).d).side_dist_x += (*(*g).d).delta_dist_x;
			(*(*g).d).map_x += (*(*g).d).step_x;
			(*(*g).d).side = 0;
		}
		else
		{
			(*(*g).d).side_dist_y += (*(*g).d).delta_dist_y;
			(*(*g).d).map_y += (*(*g).d).step_y;
			(*(*g).d).side = 1;
		}
		if ((*g).map[(*(*g).d).map_x][(*(*g).d).map_y] > 0)
			(*(*g).d).hit = 1;
	}
}

void	calc_perp_lh_ds_de_color(t_g_prop *g)
{
	if ((*(*g).d).side == 0)
		(*(*g).d).perp_wall_dist = ((*(*g).d).map_x -
			(*(*g).d).ray_pos_x + (1 - (*(*g).d).step_x) / 2)
			/ (*(*g).d).ray_dir_x;
	else
		(*(*g).d).perp_wall_dist = ((*(*g).d).map_y -
			(*(*g).d).ray_pos_y + (1 - (*(*g).d).step_y) / 2)
			/ (*(*g).d).ray_dir_y;
	(*(*g).d).line_height = (int)(WIN_H / (*(*g).d).perp_wall_dist);
	(*(*g).d).draw_start = -(*(*g).d).line_height / 2 + WIN_H / 2;
	(*(*g).d).draw_end = (*(*g).d).line_height / 2 + WIN_H / 2;
	if ((*(*g).d).draw_start < 0)
		(*(*g).d).draw_start = 0;
	if ((*(*g).d).draw_end >= WIN_H)
		(*(*g).d).draw_end = (WIN_H - 1);
	calc_color(g);
}

void	calc_color(t_g_prop *g)
{
	if ((*g).map[(*(*g).d).map_x][(*(*g).d).map_y] == 1)
		(*(*g).d).color = 16711680;
	else if ((*g).map[(*(*g).d).map_x][(*(*g).d).map_y] == 2)
		(*(*g).d).color = 65280;
	else if ((*g).map[(*(*g).d).map_x][(*(*g).d).map_y] == 3)
		(*(*g).d).color = 255;
	else if ((*g).map[(*(*g).d).map_x][(*(*g).d).map_y] == 4)
		(*(*g).d).color = 16777215;
	else
		(*(*g).d).color = 16776960;
	if ((*(*g).d).side == 1)
		(*(*g).d).color = (*(*g).d).color / 2;
}
