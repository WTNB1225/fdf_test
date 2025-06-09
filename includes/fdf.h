/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:36 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 22:58:21 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080
typedef struct s_map
{
	size_t	width;
	size_t	height;
	float	*x;
	float	*y;
	float	*z;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bps;
	int		line_width;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;


void	exit_error(char *message, bool is_syscall);
void	exit_with_fd(char *message, bool is_syscall, int fd);

size_t	get_height(const char *filename);
size_t	get_width(const char *filename);

size_t	count_width(const char *line);
void	read_file(const char *filename, t_map *map);

void	init(t_vars *vars, t_data *data);
t_data	*init_data(void);

void	put_pixel(t_data *data, int x, int y, int color);

void	free_double_ptr(char **ptr);
#endif
