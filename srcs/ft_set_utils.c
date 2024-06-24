/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:20:35 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/24 11:21:32 by ktieu            ###   ########.fr       */
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
	return (-1);
}

inline void	ft_guidance(void)
{
	ft_printf("Available set: [Julia | Mandelbrot]\n");
	ft_printf("<1>\t>Julia Argument<:\t[real number, imaginary number]\n");
	ft_printf("<2>\t>Mandelbrot Argument<:\t[None]\n");
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
	else
	{
		ft_guidance();
	}
}
