/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:39:47 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/11 23:55:23 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_data *data, t_map *map)
{
	size_t	x;
	size_t	y;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fdf");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bps,
			&data->line_width, &data->endian);
	map->x = (int *)malloc(sizeof(int) * map->width * map->height);
	map->y = (int *)malloc(sizeof(int) * map->width * map->height);
	map->z = (int *)malloc(sizeof(int) * map->width * map->height);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->x[y * map->width + x] = x; 
			map->y[y * map->width + x] = y; 
			map->z[y * map->width + x] = map->alt[y * map->width + x]; 
			x++;
		}
		y++;
	}
}
