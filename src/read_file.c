/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 01:01:49 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 20:27:20 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(const char *filename, t_map *map)
{
	map->width = get_width(filename);
	map->height = get_height(filename);
	map->alt = get_alt(filename, map);
}
