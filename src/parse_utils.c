/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:48:43 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/14 16:26:35 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	count_width(const char *line)
{
	char	**split;
	size_t	i;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	free_double_ptr(split);
	return (i);
}

int	*line_to_int(char *line, size_t width)
{
	char	**split;
	int		*array;
	size_t	i;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	i = 0;
	array = (int *)malloc(sizeof(int) * width);
	if (!array)
		return (NULL);
	i = 0;
	while (split[i])
	{
		array[i] = ft_atoi(split[i]);
		i++;
	}
	free_double_ptr(split);
	return (array);
}

unsigned int	hex_to_uint(char *str)
{
	unsigned int	sum;
	size_t			i;
	const char		*hex_table = "0123456789ABCDEF";

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sum = 0;
	str += 2;
	while (*str)
	{
		i = 0;
		while (hex_table[i])
		{
			if (hex_table[i] == *str)
				break ;
			i++;
		}
		sum = sum * 16 + i;
		str++;
	}
	return (sum);
}

unsigned int	*get_line_color(char *line, size_t width)
{
	char			**split;
	unsigned int	*line_color;
	char			*ptr;
	size_t			i;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	line_color = (unsigned int *)malloc(sizeof(unsigned int) * width);
	if (!line_color)
		return (NULL);
	i = 0;
	while (split[i])
	{
		ptr = ft_strchr(split[i], ',');
		if (!ptr)
			line_color[i++] = 0xFFFFFFFF;
		else
		{
			ptr++;
			line_color[i++] = hex_to_uint(ptr);
		}
	}
	free_double_ptr(split);
	return (line_color);
}
