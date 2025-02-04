/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:42:57 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 17:09:40 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	print_available(void)
{
	ft_putendl_fd(1, "available paramters:");
	ft_putendl_fd(1, "mandelbrot\njulia cx cy");
	exit(1);
}

static int	check_param(char *av, int ac)
{
	if (ft_strcmp(av, "mandelbrot") == 0 && ac == 2)
		return (1);
	else if (ft_strcmp(av, "julia") == 0 && ac == 4)
		return (0);
	else
	{
		ft_putendl_fd(2, "Invalid parameter");
		print_available();
	}
	return (-1);
}

int	main(int ac, char **av)
{
	int	id;

	if (ac == 1)
		print_available();
	id = check_param(av[1], ac);
	set_fract(id, av);
}
