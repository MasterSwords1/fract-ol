/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:02:41 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 21:18:26 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITERATIONS 120
# define BLACK 0x000000
# define BLUE 0x134ead
# define YELLOW 0xe0e332
# define WHITE 0xFFFFFF

typedef struct s_xorg
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_xorg;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_img;

typedef struct s_fract
{
	t_xorg	xorg;
	t_img	img;
	void	(*set)(struct s_fract *);
	int		id;
	double	x;
	double	y;
	double	cx;
	double	cy;
	double	x_min_border;
	double	x_max_border;
	double	y_min_border;
	double	y_max_border;
	double	zoom;
	int		dvg_col;
	double	x_shift;
	double	y_shift;
}	t_fract;

void	ft_putendl_fd(int fd, const char *str);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
float	ft_atof(const char *str);
int		close_win(t_fract *fract);
int		keypress(int keycode, t_fract *fract);
int		mouse_hook(int mouse_event, int x, int y, t_fract *fract);
void	julia_set(t_fract *fract);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	mandelbrot_set(t_fract *fract);
void	burning_ship_set(t_fract *fract);
void	set_fract(int id, char **av);
void	call_fract(t_fract *fract);
double	map(double x, double in_max, double out_min, double out_max);
void	init_img(t_img *img, t_xorg *xorg);

#endif
