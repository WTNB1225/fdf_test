/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:27:45 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/13 15:56:27 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map, double angle)
{
	int		x;
	int		y;
	size_t	idx;
	float	temp_y;
	float	temp_z;

	y = 0;
	while ((size_t)y < map->height)
	{
		x = 0;
		while ((size_t)x < map->width)
		{
			idx = y * map->width + x;
			temp_y = map->y[idx] * cos(angle) - map->z[idx] * sin(angle);
			temp_z = map->y[idx] * sin(angle) + map->z[idx] * cos(angle);
			map->y[idx] = temp_y;
			map->z[idx] = temp_z;
			x++;
		}
		y++;
	}
}

void	rotate_y(t_map *map, double angle)
{
	int		x;
	int		y;
	size_t	idx;
	float	temp_x;
	float	temp_z;

	y = 0;
	while ((size_t)y < map->height)
	{
		x = 0;
		while ((size_t)x < map->width)
		{
			idx = y * map->width + x;
			temp_x = map->x[idx] * cos(angle) + map->z[idx] * sin(angle);
			temp_z = -map->x[idx] * sin(angle) + map->z[idx] * cos(angle);
			map->x[idx] = temp_x;
			map->z[idx] = temp_z;
			x++;
		}
		y++;
	}
}

void	rotate_z(t_map *map, double angle)
{
	int		x;
	int		y;
	size_t	idx;
	float	temp_x;
	float	temp_y;

	y = 0;
	while ((size_t)y < map->height)
	{
		x = 0;
		while ((size_t)x < map->width)
		{
			idx = y * map->width + x;
			temp_x = map->x[idx] * cos(angle) - map->y[idx] * sin(angle);
			temp_y = map->x[idx] * sin(angle) + map->y[idx] * cos(angle);
			map->x[idx] = temp_x;
			map->y[idx] = temp_y;
			x++;
		}
		y++;
	}
}
