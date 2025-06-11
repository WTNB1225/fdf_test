/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:26:47 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/11 21:23:59 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coords_row(size_t idx, t_map *map, t_coords *coords)
{
	coords->x0 = map->x[idx];
	coords->y0 = map->y[idx];
	coords->x1 = map->x[idx + 1];
	coords->y1 = map->y[idx + 1];
}

void	set_coords_col(size_t idx, size_t down, t_map *map,
	t_coords *coords)
{
	coords->x0 = map->x[idx];
	coords->y0 = map->y[idx];
	coords->x1 = map->x[down];
	coords->y1 = map->y[down];
}

void	set_draw_params(t_draw_params *params, t_coords *coords)
{
	params->dx = abs(coords->x1 - coords->x0);
	params->dy = abs(coords->y1 - coords->y0);
	if (coords->x1 > coords->x0)
		params->sx = 1;
	else
		params->sx = -1;
	if (coords->y1 > coords->y0)
		params->sy = 1;
	else
		params->sy = -1;
	params->err = params->dx - params->dy;
}
