/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:53:12 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 23:47:13 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_coords_row(size_t idx, t_map *map, t_coords *coords)
{
	coords->x0 = map->x[idx];
	coords->y0 = map->y[idx];
	coords->x1 = map->x[idx + 1];
	coords->y1 = map->y[idx + 1];
}

static void	set_coords_col(size_t idx, size_t down, t_map *map, t_coords *coords)
{
	coords->x0 = map->x[idx];
	coords->y0 = map->y[idx];
	coords->x1 = map->x[down];
	coords->y1 = map->y[down];
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (data->line_width * y) + (data->bps / 8) * x;
	*(unsigned int *)dst = color;
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
			idx = y * width + x;
			down = (y + 1) * width + x;
			set_coords_row(idx, map, &coords);
			if (x < map->width - 1)
				draw_line(&coords, data, 0xFFFFFFFF);
			set_coords_col(idx, down, map, &coords);
			if (y < map->height - 1)
				draw_line(&coords, data, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_line(t_coords *coords, t_data *data, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;

	dx = abs(coords.x1 - coords.x0);
	dy = abs(coords.y1 - coords.y0);
	sx = -1;
	sy = -1;
	err = dx - dy;
	if (coords.x1 > coords.x0)
		sx = 1;
	if (coords.y1 > coords.y0)
		sy = 1;
	while (1)
	{
		put_pixel(data, coords.x0, coords.y0, color);
		if (coords.x0 == coords.x1 && coords.y0 == coords.y1)
			break ;
		if (2 * err > -dy)
		{
			err -= dy;
			x0 += sx;
		}


	}
}
