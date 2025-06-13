/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:27:45 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/13 14:45:02 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map, double angle)
{
	int		x;
	int		y;
	size_t	idx;

	y = 0;
	idx = 0;
	while ((size_t)y < map->height)
	{
		x = 0;
		while ((size_t)x < map->width)
		{
			idx = y * map->width + x;
			map->y[idx] = y * cos(angle) - map->z[idx] * sin(angle);
			map->z[idx] = y * sin(angle) + map->z[idx] * cos(angle);
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

	y = 0;
	idx = 0;
	while ((size_t)y < map->height)
	{
		x = 0;
		while ((size_t)x < map->width)
		{
			idx = y * map->width + x;
			map->x[idx] = x * cos(angle) + map->z[idx] * sin(angle);
			map->z[idx] = -x * sin(angle) + map->z[idx] * cos(angle);
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

	y = 0;
	idx = 0;
	while ((size_t)y < map->height)
	{
		x = 0;
		while ((size_t)x < map->width)
		{
			idx = y * map->width + x;
			map->x[idx] = x * cos(angle) - y * sin(angle);
			map->y[idx] = x * sin(angle) + y * cos(angle);
			x++;
		}
		y++;
	}
}
