/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:43:00 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:10:47 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_zn(double *a, double *b, t_fract *fract)
{
	double	tmp;

	tmp = *a;
	*a = *a * *a - *b * *b + fract->cx;
	*b = (2 * tmp * *b) + fract->cy;
}

void	julia_set(t_fract *fract)
{
	int		iter;
	double	a;
	double	b;

	iter = 0;
	a = map(fract->x, WIDTH, -fract->border, fract->border) / fract->zoom;
	b = map(fract->y, HEIGHT, -fract->border, fract->border) / fract->zoom;
	while ((a * a) + (b * b) <= 4 && iter < MAX_ITERATIONS)
	{
		julia_zn(&a, &b, fract);
		iter++;
	}
	if (iter == MAX_ITERATIONS)
		my_mlx_pixel_put(&fract->img, fract->x, fract->y, BLACK);
	else
		my_mlx_pixel_put(&fract->img, fract->x, fract->y, iter
			* fract->dvg_col);
}
