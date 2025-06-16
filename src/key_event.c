/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:11:19 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/15 01:47:51 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_key_down(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	else if (keycode == W_KEY)
		move_top(data);
	else if (keycode == A_KEY)
		move_left(data);
	else if (keycode == S_KEY)
		move_bottom(data);
	else if (keycode == D_KEY)
		move_right(data);
	else if (keycode == I_KEY)
		zoom_in(data);
	else if (keycode == O_KEY)
		zoom_out(data);
	else if (keycode == X_KEY)
		rotate_x(data);
	else if (keycode == Y_KEY)
		rotate_y(data);
	else if (keycode == Z_KEY)
		rotate_z(data);
	return (0);
}
