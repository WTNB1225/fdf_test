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
		exit_error("Failed to open file", true);
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

