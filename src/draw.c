/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:19:15 by mkok              #+#    #+#             */
/*   Updated: 2017/05/31 12:17:00 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_c_prop	*drawline(t_g_prop *g)
{
	t_c_prop	*poop;
	t_j_prop	draw;

	if (!(poop = (t_c_prop*)malloc(sizeof(t_c_prop) * WIN_H)))
		return (NULL);
	draw = drawline_help(g);
	while (1)
	{
		mlx_pixel_put((*g).mlx, (*g).win, (*g).draw_x0,
			(*g).draw_y0, (*(*g).d).color);
		if ((*g).draw_x0 == (*g).draw_x1 && (*g).draw_y0 == (*g).draw_y1)
			break ;
		draw.er2 = draw.err;
		if (draw.er2 > -(draw.dx))
		{
			draw.err -= draw.dy;
			(*g).draw_x0 += draw.sx;
		}
		if (draw.er2 < draw.dy)
		{
			draw.err += draw.dx;
			(*g).draw_y0 += draw.sy;
		}
	}
	return (poop);
}

t_j_prop	drawline_help(t_g_prop *g)
{
	t_j_prop	draw;

	draw.dx = abs((*g).draw_x1 - (*g).draw_x0);
	draw.sx = (*g).draw_x0 < (*g).draw_x1 ? 1 : -1;
	draw.dy = abs((*g).draw_y1 - (*g).draw_y0);
	draw.sy = (*g).draw_y0 < (*g).draw_y1 ? 1 : -1;
	draw.err = (draw.dx > draw.dy ? draw.dx : -(draw.dy)) / 2;
	return (draw);
}

int			render_screen(t_g_prop *g)
{
	while ((*(*g).d).poop < WIN_W)
	{
		calc_rpos_and_rdir(g);
		calc_step_and_side_dist(g);
		perform_dda(g);
		calc_perp_lh_ds_de_color(g);
		(*g).draw_x0 = (*(*g).d).poop;
		(*g).draw_y0 = (*(*g).d).draw_start;
		(*g).draw_x1 = (*(*g).d).poop;
		(*g).draw_y1 = (*(*g).d).draw_end;
		drawline(g);
		(*(*g).d).poop++;
	}
	(*(*g).d).poop = 0;
	draw_x(g);
	return (0);
}

void		clear_screen(t_g_prop *g)
{
	(*g).img = mlx_new_image((*g).mlx, WIN_W, WIN_H);
	(*g).pixel_img = mlx_get_data_addr((*g).img,
		&((*g).bpp), &((*g).s_line), &((*g).gd));
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).img, 0, 0);
	mlx_destroy_image((*g).mlx, (*g).img);
	draw_x(g);
}

void		draw_x(t_g_prop *g)
{
	(*(*g).d).color = 16711680;
	(*g).draw_x0 = 488;
	(*g).draw_y0 = 0;
	(*g).draw_x1 = 512;
	(*g).draw_y1 = 24;
	drawline(g);
	(*g).draw_x0 = 488;
	(*g).draw_y0 = 24;
	(*g).draw_x1 = 512;
	(*g).draw_y1 = 0;
	drawline(g);
}
