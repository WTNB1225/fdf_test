/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:14:27 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/13 23:06:10 by wyuki            ###   ########.fr       */
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
	int		*array;
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
		array = line_to_int(line, map->width);
		if (!array)
			(free(alt), free(line), exit_with_fd("Alloc error", false, fd));
		(ft_memcpy(&alt[i], array, sizeof(int) * map->width), i += map->width);
		line = (free(line), free(array), get_next_line(fd));
	}
	if (close(fd) == -1)
		exit_error("Failed to close the file", true);
	return (alt);
}

unsigned int	*get_color(const char *filename, t_map *map)
{
	char			*line;
	int				fd;
	unsigned int	*color;
	unsigned int	*color_line;
	size_t			i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		(free(map->alt), exit_error("Failed to open the file", true));
	color = (unsigned int *)malloc(sizeof(unsigned int) * map->width * map->height);
	if (!color)
		(free(map->alt), exit_error("Failed to allocate memory", false));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		color_line = get_line_color(line, map->width);
		if (!color_line)
		{
			(free(line), free(map->alt), free(color));
			exit_with_fd("Failed to allocate memory", false, fd);
		}
		ft_memcpy(&color[i], color_line, sizeof(unsigned int) * map->width);
		i += map->width;
		free(line);
		line = get_next_line(fd);
	}
	return (color);
}
