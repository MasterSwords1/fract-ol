/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:42:42 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/04 23:55:49 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	parse_const(const char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 1;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == 0)
		return ;
	if (str[i++] != '.')
		return (ft_putendl_fd(2, "Invalid constant value"), exit(1));
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			flag = -1;
		i++;
	}
	if (flag == -1)
		return (ft_putendl_fd(2, "Invalid constant value"), exit(1));
	return ;
}

static void	skip_space(const char **str, int *sign)
{
	while (**str == '\f' || **str == '\n' || **str == '\r'
		|| **str == '\t' || **str == '\v')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
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

float	ft_atof(const char *str)
{
	float	exp;
	float	man;
	int		sign;

	if (*str == 0)
		return (ft_putendl_fd(2, "Constant cannot be empty"), exit(1), 0);
	exp = 0;
	man = 0;
	sign = 1;
	skip_space(&str, &sign);
	parse_const(str);
	get_exp(&str, &exp);
	if (*str != '.')
		return (exp * sign);
	str++;
	get_mant(&str, &man);
	if (exp + man > 2.0)
		return (ft_putendl_fd(2, "Constant cannot be empty"), exit(1), 0);
	return (exp + man * sign);
}
