/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:43:33 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:19:42 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void inline	init_fract(t_fract *fract, char **av)
{
	if (fract->id == 0)
	{
		fract->cx = ft_atof(av[2]);
		fract->cy = ft_atof(av[3]);
	}
	fract->dvg_col = 1714190;
	fract->zoom = 1.0;
	fract->x_min_border = -2;
	fract->x_max_border = 2;
	fract->y_min_border = -2;
	fract->y_max_border = 2;
	fract->x_shift = 0;
	fract->y_shift = 0;
	if (fract->id == 0)
		fract->set = &julia_set;
	else if (fract->id == 1)
		fract->set = &mandelbrot_set;
	else
		fract->set = &burning_ship_set;
}

void	init_img(t_img *img, t_xorg *xorg)
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
	mlx_mouse_hook(fract.xorg.win, &mouse_hook, &fract);
	mlx_key_hook(fract.xorg.win, &keypress, &fract);
	mlx_hook(fract.xorg.win, 17, 1L << 0, close_win, &fract);
	mlx_loop(fract.xorg.mlx);
}

void	call_fract(t_fract *fract)
{
	if (fract->zoom < 1.0)
		fract->zoom = 1;
	fract->y = 0;
	while (fract->y < HEIGHT)
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			fract->set(fract);
			fract->x++;
		}
		fract->y++;
	}
	mlx_put_image_to_window(fract->xorg.mlx, fract->xorg.win,
		fract->img.img, 0, 0);
}
