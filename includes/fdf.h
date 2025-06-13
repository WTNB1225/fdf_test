/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:36 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/13 23:07:35 by wyuki            ###   ########.fr       */
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
# define ESC_KEY 65307

typedef struct s_map
{
	size_t			width;
	size_t			height;
	unsigned int	*color;
	int				*alt;
	float			*x;
	float			*y;
	float			*z;
	float			max_x;
	float			min_x;
	float			max_y;
	float			min_y;
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
	void	*mlx;
	void	*win;
	void	*img;
	t_map	*map;
	char	*addr;
	int		bps;
	int		line_width;
	int		endian;
}	t_data;

void			exit_error(char *message, bool is_syscall);
void			exit_with_fd(char *message, bool is_syscall, int fd);

size_t			get_height(const char *filename);
size_t			get_width(const char *filename);
int				*get_alt(const char *filename, t_map *map);
unsigned int	*get_color(const char *filename, t_map *map);

size_t			count_width(const char *line);
int				*line_to_int(char *line, size_t width);
unsigned int	*get_line_color(char *line, size_t width);
void			read_file(const char *filename, t_map *map);

void			init(t_data *data, t_map *map);

void			set_coords_row(size_t idx, t_map *map, t_coords *coords);
void			set_coords_col(size_t idx, size_t down, t_map *map, t_coords *coords);
void			set_draw_params(t_draw_params *params, t_coords *coords);

void			put_pixel(t_data *data, int x, int y, int color);
void			draw_line(t_coords *coords, t_data *data, int color);
void			draw(t_map *map, t_data *data);

int				close_window(t_data *data);
int				on_key_down(int keycode, t_data *data);

void			rotate_x(t_map *map, double angle);
void			rotate_y(t_map *map, double angle);
void			rotate_z(t_map *map, double angle);
void			isometric(t_map *map, t_data *data);

void			free_double_ptr(char **ptr);
#endif
