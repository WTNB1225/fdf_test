/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:53:12 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/11 22:49:49 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (data->line_width * y) + (data->bps / 8) * x;
	*(unsigned int *)dst = color;
}

void	draw_line(t_coords *coords, t_data *data, int color)
{
	t_draw_params	params;

	set_draw_params(&params, coords);
	while (1)
	{
		put_pixel(data, coords->x0, coords->y0, color);
		if (coords->x0 == coords->x1 && coords->y0 == coords->y1)
			break ;
		if (2 * params.err > -params.dy)
		{
			params.err -= params.dy;
			coords->x0 += params.sx;
		}
		if (2 * params.err < params.dx)
		{
			params.err += params.dx;
			coords->y0 += params.sy;
		}
	}
}

void	draw(t_map *map, t_data *data)
{
	size_t		x;
	size_t		y;
	size_t		idx;
	size_t		down;
	t_coords	coords;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			idx = y * map->width + x;
			down = (y + 1) * map->width + x;
			if (x < map->width - 1)
			{
				set_coords_row(idx, map, &coords);
				draw_line(&coords, data, 0xFFFFFFFF);
			}
			if (y < map->height - 1)
			{
				set_coords_col(idx, down, map, &coords);
				draw_line(&coords, data, 0xFFFFFFFF);
			}
			x++;
		}
		y++;
	}
}
