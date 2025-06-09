/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:39:47 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 23:13:45 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_vars *vars, t_data *data)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bps, &data->line_width, &data->endian);
}
