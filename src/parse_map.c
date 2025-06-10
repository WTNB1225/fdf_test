/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:14:27 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 20:36:52 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_width(const char *filename)
{
	int		fd;
	size_t	width;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open the file", true);
	line = get_next_line(fd);
	if (!line)
		exit_with_fd("Invalid map", false, fd);
	width = count_width(line);
	while (line)
	{
		if (width != count_width(line))
		{
			free(line);
			exit_with_fd("Invalid map", false, fd);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_error("Failed to close the file", true);

	return (width);
}

size_t	get_height(const char *filename)
{
	int		fd;
	size_t	height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open the file", true);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_error("Failed to close the file", true);
	return (height);
}

int	*get_alt(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		*int_array;
	int		*alt;
	size_t	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open the file", true);
	alt = (int *)malloc(sizeof(int) * (map->width * map->height));
	if (!alt)
		exit_error("Failed to allocate memory", false);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		int_array = line_to_int(line);
		if (!int_array)
			(free(alt), exit_with_fd("Failed to allocate memory", false, fd));
		ft_memcpy(line + (map->width * i), int_array, map->width);
		free(int_array);
	}
	if (close(fd) == -1)
		exit_error("Failed to close the file", true);
	return (alt);
}