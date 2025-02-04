/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:43:36 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:26:52 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fract *fract)
{
	mlx_destroy_image(fract->xorg.mlx, fract->img.img);
	mlx_clear_window(fract->xorg.mlx, fract->xorg.win);
	mlx_destroy_window(fract->xorg.mlx, fract->xorg.win);
	exit(0);
	return (0);
}

int	keypress(int keycode, t_fract *fract)
{
	if (keycode == 65307)
		close_win(fract);
	if (keycode == 91)
		fract->dvg_col += 100;
	else if (keycode == 93)
		fract->dvg_col -= 100;
	else if (keycode == 65361)
		fract->x_shift += map(fract->x_shift - 10, WIDTH,
				fract->x_min_border, fract->x_max_border) / fract->zoom;
	else if (keycode == 65363)
		fract->x_shift -= map(fract->x_shift - 10, WIDTH,
				fract->x_min_border, fract->x_max_border) / fract->zoom;
	else if (keycode == 65362)
		fract->y_shift += map(fract->y_shift - 10, HEIGHT,
				fract->y_min_border, fract->y_max_border) / fract->zoom;
	else if (keycode == 65364)
		fract->y_shift -= map(fract->y_shift - 10, HEIGHT,
				fract->y_min_border, fract->y_max_border) / fract->zoom;
	else
		return (0);
	call_fract(fract);
	return (0);
}

int	mouse_hook(int mouse_event, int x, int y, t_fract *fract)
{
	double	z;
	double	mouse_x;
	double	mouse_y;

	if (mouse_event == 4)
	{
		z = 0.9;
		fract->zoom *= 1.1;
	}
	else if (mouse_event == 5)
	{
		z = 1.1;
		fract->zoom *= 0.9;
	}
	else
		return (0);
	mouse_x = map(x, WIDTH, fract->x_min_border, fract->x_max_border);
	mouse_y = map(y, HEIGHT, fract->y_min_border, fract->y_max_border);
	fract->x_min_border = (fract->x_min_border - mouse_x) * z + mouse_x;
	fract->x_max_border = (fract->x_max_border - mouse_x) * z + mouse_x;
	fract->y_min_border = (fract->y_min_border - mouse_y) * z + mouse_y;
	fract->y_max_border = (fract->y_max_border - mouse_y) * z + mouse_y;
	call_fract(fract);
	return (0);
}
