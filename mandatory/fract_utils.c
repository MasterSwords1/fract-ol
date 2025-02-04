/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:39:48 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:12:26 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double x, double in_max, double out_min, double out_max)
{
	return (x * (out_max - out_min) / in_max + out_min);
}

static void	init_fract(t_fract *fract, char **av)
{
	fract->border = 2;
	if (fract->id == 0)
	{
		fract->cx = ft_atof(av[2]);
		fract->cy = ft_atof(av[3]);
	}
	fract->dvg_col = 0x000A0AL * 667;
	fract->zoom = 1;
}

static void	init_img(t_img *img, t_xorg *xorg)
{
	img->img = mlx_new_image(xorg->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_lenght, &img->endian);
}

void	set_fract(int id, char **av)
{
	t_fract	fract;

	fract.id = id;
	init_fract(&fract, av);
	fract.xorg.mlx = mlx_init();
	fract.xorg.win = mlx_new_window(fract.xorg.mlx, WIDTH, HEIGHT, av[1]);
	init_img(&fract.img, &fract.xorg);
	call_fract(&fract);
	mlx_mouse_hook(fract.xorg.win, mouse_hook, &fract);
	mlx_key_hook(fract.xorg.win, &keypress, &fract);
	mlx_hook(fract.xorg.win, 17, 1L << 0, close_win, &fract.xorg);
	mlx_loop(fract.xorg.mlx);
}

void	call_fract(t_fract *fract)
{
	void	(*fptr)(t_fract *);

	if (fract->zoom < 1.0)
		fract->zoom = 1;
	if (fract->id == 0)
		fptr = &julia_set;
	else
		fptr = &mandelbrot_set;
	fract->x = 0;
	fract->y = 0;
	while (fract->y < HEIGHT)
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			fptr(fract);
			fract->x++;
		}
		fract->y++;
	}
	mlx_put_image_to_window(fract->xorg.mlx, fract->xorg.win,
		fract->img.img, 0, 0);
}
