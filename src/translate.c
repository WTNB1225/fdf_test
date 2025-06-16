/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:05:04 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/15 01:33:23 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_top(t_data *data)
{
	size_t	i;
	t_map	*map;

	i = 0;
	map = data->map;
	ft_memset(data->addr, 0, HEIGHT * data->line_width);
	while (i < map->width * map->height)
	{
		map->y[i] = map->y[i] - 10.0;
		i++;
	}
	draw(map, data);
}

void	move_bottom(t_data *data)
{
	size_t	i;
	t_map	*map;

	i = 0;
	map = data->map;
	ft_memset(data->addr, 0, HEIGHT * data->line_width);
	while (i < map->width * map->height)
	{
		map->y[i] = map->y[i] + 10.0;
		i++;
	}
	draw(map, data);
}

void	move_left(t_data *data)
{
	size_t	i;
	t_map	*map;

	i = 0;
	map = data->map;
	ft_memset(data->addr, 0, HEIGHT * data->line_width);
	while (i < map->width * map->height)
	{
		map->x[i] = map->x[i] - 10.0;
		i++;
	}
	draw(map, data);
}

void	move_right(t_data *data)
{
	size_t	i;
	t_map	*map;

	i = 0;
	map = data->map;
	ft_memset(data->addr, 0, HEIGHT * data->line_width);
	while (i < map->width * map->height)
	{
		map->x[i] = map->x[i] + 10.0;
		i++;
	}
	draw(map, data);
}
