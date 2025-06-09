/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:39:47 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 22:51:19 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->img = NULL;
	data->addr = NULL;
	data->bps = 0;
	data->line_width = 0;
	data->endian = 0;
	return (data);
}

void	init(t_vars *vars, t_data *data)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bps, &data->line_width, &data->endian);
}
