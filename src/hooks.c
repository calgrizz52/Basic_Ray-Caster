/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <calgrizz52@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:19:52 by mkok              #+#    #+#             */
/*   Updated: 2017/05/31 12:10:06 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		wolf_key_funct(int keycode, t_g_prop *g)
{
	ft_putstr("Key event:\n");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_UP)
		move_up(g);
	if (keycode == KEY_DOWN)
		move_down(g);
	if (keycode == KEY_RIGHT)
		move_right(g);
	if (keycode == KEY_LEFT)
		move_left(g);
	return (0);
}

int		wolf_mouse_hook(int button, int x, int y, t_g_prop *g)
{
	if (button == KEY_MOUSE_CLIC_L && (x >= 488 && y <= 24))
		exit(0);
	return (0);
}
