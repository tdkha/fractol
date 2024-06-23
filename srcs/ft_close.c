/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:03:58 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/23 16:43:47 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_close(t_fractol *fractol, int exit_code)
{
	if (fractol)
	{
		if (fractol->img_struct.img)
			mlx_destroy_image(fractol->mlx, fractol->img_struct.img);
		if (fractol->window && fractol->mlx)
		{
			mlx_destroy_window(fractol->mlx, fractol->window);
		}
		if (fractol->mlx)
		{
			mlx_destroy_display(fractol->mlx);
			free(fractol->mlx);
		}
	}
	exit(exit_code);
}

void	ft_close_print(t_fractol *fractol, int exit_code, char *msg)
{
	ft_printf_fd(2, "fractol: %s\n", msg);
	ft_close(fractol, exit_code);
}
