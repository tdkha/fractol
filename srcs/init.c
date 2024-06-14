/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:07:24 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/14 15:24:22 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


static void	ft_guidance()
{
	ft_printf("Available set: [Julia | Mandelbrot]\n");
	ft_printf(">Julia Argument<:\t[real number, imaginary number]\n");
	ft_printf(">Mandelbrot Argument<:\t[None]\n");
	exit(1);
}

static void	ft_define_set_type(int ac, char **av, t_fractol *fractol)
{
	if (ft_strncmp(av[1], "Julia", sizeof("Julia")))
	{
		
	}
	else if (ft_strncmp(av[1], "Mandelbrot", sizeof("Mandelbrot")))
	{
		
	}
	else
	{
		ft_guidance();
	}
}

void	ft_fractol_init(int ac, char **av, t_fractol *fractol)
{
	
}
