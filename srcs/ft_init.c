/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:16:13 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/23 16:45:59 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_guidance(void)
{
	ft_printf("Available set: [Julia | Mandelbrot]\n");
	ft_printf("<1>\t>Julia Argument<:\t[real number, imaginary number]\n");
	ft_printf("<2>\t>Mandelbrot Argument<:\t[None]\n");
	exit(1);
}

static void	ft_define_set_type(int ac, char **av, t_fractol *fractol)
{
	if (ac == 4 && ft_strcmp(av[1], "Julia"))
	{
		fractol->type = JULIA;
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

static inline void	ft_mlx_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		ft_close_print(fractol, EXIT_FAILURE, "Failed to initialize mlx");
	fractol->img_struct.img = mlx_new_image(fractol->mlx, WINDOW_W, WINDOW_H);
	if (fractol->img_struct.img == NULL)
		ft_close_print(fractol, EXIT_FAILURE, "Failed to initialize image");
	fractol->img_struct.addr = mlx_get_data_addr(
			fractol->img_struct.img, &fractol->img_struct.bits_per_pixel,
			&fractol->img_struct.line_length, &fractol->img_struct.endian);
	if (fractol->img_struct.addr == NULL)
		ft_close_print(fractol, EXIT_FAILURE, "Failed to get img address");
	fractol->window = mlx_new_window(
			fractol->mlx,
			WINDOW_W, WINDOW_H, "Fractol42");
	if (fractol->window == NULL)
		ft_close_print(fractol, EXIT_FAILURE, "Failed to initialize window");
}

void	ft_fractol_init(int ac, char **av, t_fractol *fractol)
{
	ft_define_set_type(ac, av, fractol);
	fractol->mlx = NULL;
	fractol->img_struct.img = NULL;
	ft_mlx_init(fractol);
	fractol->min_x = -2;
	fractol->max_x = 2;
	fractol->min_y = -2;
	fractol->max_y = 2;
	fractol->iteration = 100;
	fractol->zoom_ratio = 1;
	ft_random_colors(fractol);
}
