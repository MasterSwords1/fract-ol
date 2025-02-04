/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:43:30 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:18:42 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_zn(double *a, double *b, t_fract *fract)
{
	double	tmp;

	tmp = *a;
	*a = *a * *a - (*b * *b) + fract->cx;
	*b = (2 * tmp * *b) + fract->cy;
}

void	julia_set(t_fract *fract)
{
	int		iter;
	double	a;
	double	b;

	iter = 0;
	a = map(fract->x + fract->x_shift, WIDTH,
			fract->x_min_border, fract->x_max_border) + fract->x_shift;
	b = map(fract->y + fract->y_shift, HEIGHT,
			fract->y_min_border, fract->y_max_border) + fract->y_shift;
	while ((a * a) + (b * b) <= 4 && iter < MAX_ITERATIONS)
	{
		julia_zn(&a, &b, fract);
		iter++;
	}
	if (iter == MAX_ITERATIONS)
		my_mlx_pixel_put(&fract->img, fract->x, fract->y, BLACK);
	else
		my_mlx_pixel_put(&fract->img, fract->x, fract->y,
			iter * fract->dvg_col);
}
