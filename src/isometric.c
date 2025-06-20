/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:40:13 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/16 16:43:53 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_max_and_min(t_map *map)
{
	size_t	i;

	i = 0;
	map->min_x = map->x[i];
	map->max_x = map->x[i];
	map->min_y = map->y[i];
	map->max_y = map->y[i];
	while (i < map->width * map->height)
	{
		if (map->x[i] > map->max_x)
			map->max_x = map->x[i];
		if (map->y[i] > map->max_y)
			map->max_y = map->y[i];
		if (map->x[i] < map->min_x)
			map->min_x = map->x[i];
		if (map->y[i] < map->min_y)
			map->min_y = map->y[i];
		i++;
	}
}

int	get_tile_size(t_map *map)
{
	int	tile_width;
	int	tile_height;

	tile_width = WIDTH / (map->max_x - map->min_x);
	tile_height = HEIGHT / (map->max_y - map->min_y);
	if (tile_width <= tile_height)
		return (tile_width);
	return (tile_height);
}

void	add_offset(t_map *map)
{
	size_t	i;
	int		tile_size;
	int		offset_x;
	int		offset_y;

	set_max_and_min(map);
	tile_size = get_tile_size(map);
	offset_x = (WIDTH / 2) - (map->max_x + map->min_x) * tile_size / 2;
	offset_y = (HEIGHT / 2) - (map->max_y + map->min_y) * tile_size / 2;
	i = 0;
	while (i < map->width * map->height)
	{
		map->x[i] = map->x[i] * tile_size + offset_x;
		map->y[i] = map->y[i] * tile_size + offset_y;
		i++;
	}
}

void	isometric(t_map *map, t_data *data)
{
	size_t	i;
	float	prev_x;

	i = 0;
	while (i < map->width * map->height)
	{
		prev_x = map->x[i];
		map->x[i] = (map->x[i] - map->y[i]) * cos(30 * M_PI / 180.0);
		map->y[i] = (map->y[i] + prev_x) * sin(30 * M_PI / 180.0) - map->z[i];
		i++;
	}
	add_offset(map);
	draw(map, data);
}
