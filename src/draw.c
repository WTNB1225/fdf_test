/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:53:12 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/15 01:17:04 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr + (data->line_width * y) + (data->bps / 8) * x;
	*(unsigned int *)dst = color;
}

t_rgb	lerp(t_rgb rgb_1, t_rgb rgb_2, float ratio)
{
	t_rgb	result;

	result.r = round(rgb_1.r + (rgb_2.r - rgb_1.r) * (ratio));
	result.g = round(rgb_1.g + (rgb_2.g - rgb_1.g) * (ratio));
	result.b = round(rgb_1.b + (rgb_2.b - rgb_1.b) * (ratio));
	return (result);
}

unsigned int	calc_color(unsigned int c1, unsigned int c2, float ratio)
{
	t_rgb	rgb_1;
	t_rgb	rgb_2;
	t_rgb	result;

	rgb_1.r = c1 >> 16 & 0xFF;
	rgb_2.r = c2 >> 16 & 0xFF;
	rgb_1.g = c1 >> 8 & 0xFF;
	rgb_2.g = c2 >> 8 & 0xFF;
	rgb_1.b = c1 & 0xFF;
	rgb_2.b = c2 & 0xFF;
	result = lerp(rgb_1, rgb_2, ratio);
	return (result.r << 16 | result.g << 8 | result.b);
}

void	draw_line(t_coords *coords, t_data *data, unsigned int color,
			unsigned int next_color)
{
	t_draw_params	params;
	size_t			total_steps;
	size_t			step;
	float			ratio;
	long long int	err2;

	set_draw_params(&params, coords);
	total_steps = fmax(abs(coords->x1 - coords->x0),
			abs(coords->y1 - coords->y0));
	step = 0;
	while (1)
	{
		ratio = (float)step / total_steps;
		step++;
		put_pixel(data, coords->x0, coords->y0, calc_color(color, next_color, ratio));
		if (coords->x0 == coords->x1 && coords->y0 == coords->y1)
			break ;
		err2 = 2 * params.err;
		if (err2 > -params.dy)
		{
			params.err -= params.dy;
			coords->x0 += params.sx;
		}
		if (err2 < params.dx)
		{
			params.err += params.dx;
			coords->y0 += params.sy;
		}
	}
}

void	clear_screen(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < data->line_width)
		{
			put_pixel(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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
				draw_line(&coords, data, data->map->color[idx], data->map->color[idx + 1]);
			}
			if (y < map->height - 1)
			{
				set_coords_col(idx, down, map, &coords);
				draw_line(&coords, data, data->map->color[idx], data->map->color[down]);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
