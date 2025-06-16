/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:36:40 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/15 01:45:55 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_data *data)
{
	size_t	i;
	t_map	*map;

	i = 0;
	map = data->map;
	ft_bzero(data->addr, HEIGHT * data->line_width);
	while (i < map->width * map->height)
	{
		map->x[i] = map->x[i] * 1.05;
		map->y[i] = map->y[i] * 1.05;
		i++;
	}
	draw(map, data);
}

void	zoom_out(t_data *data)
{
	size_t	i;
	t_map	*map;

	i = 0;
	map = data->map;
	ft_bzero(data->addr, HEIGHT * data->line_width);
	while (i < map->width * map->height)
	{
		map->x[i] = map->x[i] / 1.05;
		map->y[i] = map->y[i] / 1.05;
		i++;
	}
	draw(map, data);
}
