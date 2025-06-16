/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthograpic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:36:12 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/16 19:25:15 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	orthograpic(t_map *map, t_data *data)
{
	int	x;
	int	y;
	size_t	idx;

	y = 0;
	while ((size_t)y < map->height)
	{
		x = 0;
		while ((size_t)x < map->width)
		{
			idx = y * map->width + x;
			map->x[idx] = x;
			map->y[idx] = y;
			x++;
		}
		y++;
	}
	ft_bzero(data->addr, HEIGHT * data->line_width);
	add_offset(map);
	draw(map, data);
}
