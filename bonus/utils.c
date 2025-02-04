/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:43:13 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:15:35 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putendl_fd(int fd, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
	write(fd, "\n", 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i]
		&& (unsigned char) s1[i] == (unsigned char) s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (int)(y * img->line_lenght + x
			* (img->bits_per_pixel * 0.125));
	*(unsigned int *)dst = color;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
