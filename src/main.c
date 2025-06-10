/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:07:17 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 23:14:01 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;
	t_vars	vars;

	if (ac != 2)
		exit_error("Usage : ./fdf <filename>", false);
	read_file(av[1], &map);
	init(&vars, &data);

	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, data.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(map.alt);
	free(vars.mlx);
	return (0);
}
