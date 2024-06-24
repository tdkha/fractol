/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:22:25 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/24 11:27:08 by ktieu            ###   ########.fr       */
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
}

inline void	ft_guidance(void)
{
	ft_printf("Available set: [Julia | Mandelbrot]\n");
	ft_printf("<1>\t>Mandelbrot Argument<:\t[None]\n");
	ft_printf("<2>\t>Julia Argument<:\t[real number, imaginary number]\n");
	ft_printf("<3>\t>Newton Argument<:\t[None]\n");
	exit(1);
}

inline void	ft_define_set_type(int ac, char **av, t_fractol *fractol)
{
	if (ac == 4 && ft_strcmp(av[1], "Julia") == 0)
	{
		fractol->type = JULIA;
		fractol->julia_values.real = ft_atold(av[2]);
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
