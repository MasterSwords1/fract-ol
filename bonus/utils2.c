/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:42:42 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/06 04:52:09 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	parse_const(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (ft_putendl_fd(2, "Invalid constant value"), exit(1));
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == 0)
		return ;
	if (str[i] == '.')
		i++;
	if (!ft_isdigit(str[i]))
		return (ft_putendl_fd(2, "Invalid constant value"), exit(1));
	i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != 0)
		return (ft_putendl_fd(2, "Invalid constant value"), exit(1));
	return ;
}

static void	get_exp(const char **str, float *exp)
{
	while (ft_isdigit(**str))
	{
		*exp = (*exp * 10) + (**str - 48);
		if (*exp > 2.0)
		{
			ft_putendl_fd(2, "Invalid constant value");
			exit(1);
		}
		(*str)++;
	}
}

static void	get_mant(const char **str, float *man)
{
	long	div;

	div = 1;
	while (ft_isdigit(**str))
	{
		*man = (*man * 10) + (**str - 48);
		div *= 10;
		(*str)++;
	}
	*man = *man / div;
}

static void	skip_sign(const char **str, int *sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

float	ft_atof(const char *str)
{
	float	exp;
	float	man;
	int		sign;

	if (*str == 0)
		return (ft_putendl_fd(2, "Constant cannot be empty"), exit(1), 0);
	parse_const(str);
	sign = 1;
	skip_sign(&str, &sign);
	exp = 0;
	get_exp(&str, &exp);
	if (*str != '.')
		return (exp * sign);
	str++;
	man = 0;
	get_mant(&str, &man);
	if (exp + man > 2.0)
		return (ft_putendl_fd(2, "Invalid constant value"), exit(1), 0);
	return (exp + man * sign);
}
