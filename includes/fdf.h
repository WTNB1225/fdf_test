/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:36 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 23:42:17 by wyuki            ###   ########.fr       */
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
	int		*alt;
	float	*x;
	float	*y;
	float	*z;
}	t_map;

typedef struct s_coords
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_coords;

typedef struct s_draw_params
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_draw_params;

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
int		*get_alt(const char *filename, t_map *map);

size_t	count_width(const char *line);
int		*line_to_int(char *line);
void	read_file(const char *filename, t_map *map);

void	init(t_vars *vars, t_data *data);

void	set_coords_row(size_t idx, t_map *map, t_coords *coords);
void	set_coords_col(size_t idx, size_t down, t_map *map, t_coords *coords);
void	set_draw_params(t_draw_params *params, t_coords *coords);

void	put_pixel(t_data *data, int x, int y, int color);
void	draw_line(t_coords *coords, t_data *data, int color);

void	free_double_ptr(char **ptr);
#endif
