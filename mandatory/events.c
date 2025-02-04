/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:39:30 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 16:39:31 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fract *fract)
{
	mlx_clear_window(fract->xorg.mlx, fract->xorg.win);
	mlx_destroy_display(fract->xorg.mlx);
	mlx_destroy_window(fract->xorg.mlx, fract->xorg.win);
	exit(0);
	return (0);
}

int	keypress(int keycode, t_fract *fract)
{
	if (keycode == 65307)
		close_win(fract);
	return (0);
}

int	mouse_hook(int mouse_event, int x, int y, t_fract *fract)
{
	if (mouse_event == 4)
		fract->zoom += 1.5;
	if (mouse_event == 5)
		fract->zoom -= 1.5;
	mlx_clear_window(fract->xorg.mlx, fract->xorg.win);
	call_fract(fract);
	return (x + y * 0);
}
