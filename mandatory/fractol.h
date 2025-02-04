/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:02:41 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:21:46 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

# define HEIGHT 600
# define WIDTH 600
# define MAX_ITERATIONS 70
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
	int		id;
	double	x;
	double	y;
	double	cx;
	double	cy;
	int		border;
	int		zoom;
	long	dvg_col;
}	t_fract;

void	ft_putendl_fd(int fd, const char *str);
float	ft_atof(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
float	ft_atof(const char *str);
int		close_win(t_fract *fract);
int		keypress(int keycode, t_fract *fract);
int		mouse_hook(int mouse_event, int x, int y, t_fract *fract);
void	julia_set(t_fract *fract);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	mandelbrot_set(t_fract *fract);
void	set_fract(int id, char **av);
void	call_fract(t_fract *fract);
double	map(double x, double in_max, double out_min, double out_max);
int		ft_isdigit(int c);

#endif
