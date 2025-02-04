/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:42:53 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:10:49 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandel_zn(double *a, double *b, double x, double y)
{
	double	tmp;

	tmp = *a;
	*a = *a * *a - *b * *b + x;
	*b = (2 * tmp * *b) + y;
}

void	mandelbrot_set(t_fract *fract)
{
	int		iter;
	double	a;
	double	b;

	iter = 0;
	a = map(fract->x, WIDTH, -fract->border, fract->border) / fract->zoom;
	b = map(fract->y, HEIGHT, -fract->border, fract->border) / fract->zoom;
	fract->cx = a;
	fract->cy = b;
	while (fract->cx * fract->cx + fract->cy * fract->cy <= 4
		&& iter < MAX_ITERATIONS)
	{
		mandel_zn(&fract->cx, &fract->cy, a, b);
		iter++;
	}
	if (iter == MAX_ITERATIONS)
		my_mlx_pixel_put(&fract->img, fract->x, fract->y, BLACK);
	else
		my_mlx_pixel_put(&fract->img, fract->x, fract->y, iter
			* fract->dvg_col);
}
