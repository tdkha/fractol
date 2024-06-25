/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:00:45 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/25 17:30:55 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_window_close(void *void_struct)
{
	t_fractol	*fractol;

	fractol = (t_fractol *) void_struct;
	ft_close(fractol, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	ft_fractol_init(ac, av, &fractol);
	mlx_hook(fractol.window, EVENT_CLOSE_BTN, 0, ft_window_close, &fractol);
	mlx_key_hook(fractol.window, ft_keyboard_hook, &fractol);
	mlx_mouse_hook(fractol.window, ft_mouse_hook, &fractol);
	mlx_loop_hook(fractol.mlx, ft_loop_hook, &fractol);
	mlx_loop(fractol.mlx);
	ft_close(&fractol, EXIT_SUCCESS);
}
