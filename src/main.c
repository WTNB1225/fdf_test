/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:07:17 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/14 16:24:53 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;

	if (ac != 2)
		exit_error("Usage : ./fdf <filename>", false);
	read_file(av[1], &map);
	init(&data, &map);
	data.map = &map;
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1 << 0, on_key_down, &data);
	isometric(&map, &data);
	mlx_loop(data.mlx);
	return (0);
}
	//size_t	i;
	//size_t	j;

	//j = 0;
	//while (j < map.height)
	//{
	//	i = 0;
	//	while (i < map.width)
	//	{
	//		printf("%d ", map.alt[i]);
	//		i++;
	//	}
	//	printf("\n");
	//	j++;
	//}
