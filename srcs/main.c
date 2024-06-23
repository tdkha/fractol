/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:00:45 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/23 16:46:27 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	ft_fractol_init(ac, av, &fractol);
	mlx_key_hook(fractol.window, ft_keyboard_hook, &fractol);
	mlx_mouse_hook(fractol.window, ft_mouse_hook, &fractol);
	mlx_loop_hook(fractol.mlx, ft_loop_hook, &fractol);
	mlx_loop(fractol.mlx);
	ft_close(&fractol, EXIT_SUCCESS);
}
