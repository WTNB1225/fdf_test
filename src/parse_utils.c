/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:48:43 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/12 00:16:28 by wyuki            ###   ########.fr       */
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
