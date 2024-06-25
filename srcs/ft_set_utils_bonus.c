/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:22:25 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/25 17:35:08 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

inline int	ft_set_execute(t_fractol *fractol, int row, int col)
{
	if (fractol->type == MANDELBROT)
	{
		return (ft_set_mandelbrot(fractol, row, col, 0));
	}
	else if (fractol->type == JULIA)
	{
		return (ft_set_julia(fractol, row, col));
	}
	else if (fractol->type == NEWTON)
	{
		return (ft_set_newton(fractol, row, col));
	}
	return (-1);
}

inline void	ft_guidance(void)
{
	ft_printf("Available set: [Julia | Mandelbrot | Newton]\n");
	ft_printf("<1>\t>Mandelbrot Argument<:\t[None]\n");
	ft_printf("<2>\t>Julia Argument<:\t[real number, imaginary number]\n");
	ft_printf("<3>\t>Newton Argument<:\t[None]\n");
	exit(1);
}

static inline int	skip_leading_characters(char *str, int skip_sign)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (skip_sign == 1)
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
	}
	return (i);
}

inline int	ft_float_param_check(
	char *str, int i,
	int found_dot, int has_digits)
{
	i = skip_leading_characters(str, 1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			has_digits = 1;
		else if (str[i] == '.')
		{
			if (found_dot)
				return (-1);
			found_dot = 1;
		}
		else if (ft_isdigit(str[i]))
		{
			i = skip_leading_characters(str, 0);
			if (str[i] != '\0')
				return (-1);
			break ;
		}
		else
			return (-1);
		i++;
	}
	if (!has_digits)
		return (-1);
	return (0);
}

inline void	ft_define_set_type(int ac, char **av, t_fractol *fractol)
{
	if (ac == 4 && ft_strcmp(av[1], "Julia") == 0)
	{
		fractol->type = JULIA;
		if (ft_float_param_check(av[2], 0, 0, 0) == -1)
			ft_close_print(fractol, 1,
				"Invalid parameter for real number");
		fractol->julia_values.real = ft_atold(av[2]);
		if (ft_float_param_check(av[3], 0, 0, 0) == -1)
			ft_close_print(fractol, 1,
				"Invalid parameter for imaginary number");
		fractol->julia_values.imaginary = ft_atold(av[3]);
	}
	else if (ac == 2 && ft_strcmp(av[1], "Mandelbrot") == 0)
	{
		fractol->type = MANDELBROT;
	}
	else if (ac == 2 && ft_strcmp(av[1], "Newton") == 0)
	{
		fractol->type = NEWTON;
	}
	else
	{
		ft_guidance();
	}
}
