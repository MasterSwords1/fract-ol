/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:43:39 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:24:00 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_fabs(double c)
{
	if (c < 0.0)
		return (c * -1);
	return (c);
}

static void	burning_ship_zn(double *a, double *b, double x, double y)
{
	double	tmp;

	tmp = *a;
	*a = *a * *a - (*b * *b) + x;
	*b = ft_fabs((2 * tmp * *b)) + y;
}

void	burning_ship_set(t_fract *fract)
{
	int		iter;
	double	a;
	double	b;

	iter = 0;
	a = map(fract->x + fract->x_shift, WIDTH,
			fract->x_min_border, fract->x_max_border) + fract->x_shift;
	b = map(fract->y + fract->y_shift, HEIGHT,
			fract->y_min_border, fract->y_max_border) + fract->y_shift;
	fract->cx = a;
	fract->cy = b;
	while (fract->cx * fract->cx + fract->cy * fract->cy <= 4
		&& iter < MAX_ITERATIONS)
	{
		burning_ship_zn(&fract->cx, &fract->cy, a, b);
		iter++;
	}
	if (iter == MAX_ITERATIONS)
		my_mlx_pixel_put(&fract->img, fract->x, fract->y, BLACK);
	else
		my_mlx_pixel_put(&fract->img, fract->x, fract->y,
			iter * fract->dvg_col);
}
