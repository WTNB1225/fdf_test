/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:27:45 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/16 15:44:45 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_data *data)
{
	int		x;
	int		y;
	size_t	idx;
	float	temp_y;
	float	temp_z;

	y = 0;
	while ((size_t)y < data->map->height)
	{
		x = 0;
		while ((size_t)x < data->map->width)
		{
			idx = y * data->map->width + x;
			temp_y = data->map->y[idx] * cos(1 * M_PI / 180.0) - data->map->z[idx] * sin(1 * M_PI / 180.0);
			temp_z = data->map->y[idx] * sin(1 * M_PI / 180.0) + data->map->z[idx] * cos(1 * M_PI / 180.0);
			data->map->y[idx] = temp_y;
			data->map->z[idx] = temp_z;
			x++;
		}
		y++;
	}
	ft_bzero(data->addr, HEIGHT * data->line_width);
	add_offset(data->map);
	draw(data->map, data);
}

void	rotate_y(t_data *data)
{
	int		x;
	int		y;
	size_t	idx;
	float	temp_x;
	float	temp_z;

	y = 0;
	while ((size_t)y < data->map->height)
	{
		x = 0;
		while ((size_t)x < data->map->width)
		{
			idx = y * data->map->width + x;
			temp_x = data->map->x[idx] * cos(1 * M_PI / 180.0) + data->map->z[idx] * sin(1 * M_PI / 180.0);
			temp_z = -data->map->x[idx] * sin(1 * M_PI / 180.0) + data->map->z[idx] * cos(1 * M_PI / 180.0);
			data->map->x[idx] = temp_x;
			data->map->z[idx] = temp_z;
			x++;
		}
		y++;
	}
	ft_bzero(data->addr, HEIGHT * data->line_width);
	add_offset(data->map);
	draw(data->map, data);
}

void	rotate_z(t_data *data)
{
	int		x;
	int		y;
	size_t	idx;
	float	temp_x;
	float	temp_y;

	y = 0;
	while ((size_t)y < data->map->height)
	{
		x = 0;
		while ((size_t)x < data->map->width)
		{
			idx = y * data->map->width + x;
			temp_x = data->map->x[idx] * cos(1 * M_PI / 180.0) - data->map->y[idx] * sin(1 * M_PI / 180.0);
			temp_y = data->map->x[idx] * sin(1 * M_PI / 180.0) + data->map->y[idx] * cos(1 * M_PI / 180.0);
			data->map->x[idx] = temp_x;
			data->map->y[idx] = temp_y;
			x++;
		}
		y++;
	}
	ft_bzero(data->addr, HEIGHT * data->line_width);
	add_offset(data->map);
	draw(data->map, data);
}
