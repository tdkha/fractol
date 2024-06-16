/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:18:27 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/16 23:52:37 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_loop_hook(void *void_struct)
{
	ft_display((t_fractol *) void_struct);
}

static inline void	ft_arrow_keyboard_handler(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		fractol->min_y += (fractol->zoom_ratio * 0.1);
		fractol->max_y += (fractol->zoom_ratio * 0.1);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		fractol->min_y -= (fractol->zoom_ratio * 0.1);
		fractol->max_y -= (fractol->zoom_ratio * 0.1);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		fractol->min_x += (fractol->zoom_ratio * 0.1);
		fractol->max_x += (fractol->zoom_ratio * 0.1);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		fractol->min_x -= (fractol->zoom_ratio * 0.1);
		fractol->max_x -= (fractol->zoom_ratio * 0.1);
	}
}

int	ft_keyboard_hook(int keycode, void *void_struct)
{
	t_fractol	*fractol;

	fractol = (t_fractol *) void_struct;
	if (keycode == KEY_ESC)
	{
		ft_close(fractol, EXIT_SUCCESS);
		return (0);
	}
	ft_arrow_keyboard_handler(keycode, fractol);
}