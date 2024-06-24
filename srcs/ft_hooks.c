/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:18:27 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/24 11:35:03 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_loop_hook(void *void_struct)
{
	ft_display((t_fractol *) void_struct);
}

static inline void	ft_arrow_keyboard_handler(int keycode, t_fractol *fractol)
{
	long double	change_rate;

	change_rate = fractol->change_rate;
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		fractol->min_y += (fractol->zoom_ratio * change_rate);
		fractol->max_y += (fractol->zoom_ratio * change_rate);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		fractol->min_y -= (fractol->zoom_ratio * change_rate);
		fractol->max_y -= (fractol->zoom_ratio * change_rate);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		fractol->min_x += (fractol->zoom_ratio * change_rate);
		fractol->max_x += (fractol->zoom_ratio * change_rate);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		fractol->min_x -= (fractol->zoom_ratio * change_rate);
		fractol->max_x -= (fractol->zoom_ratio * change_rate);
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
	if (keycode == KEY_C)
		ft_random_colors(fractol);
	if (keycode == KEY_I)
		fractol->iteration *= (1 + fractol->change_rate);
	if (keycode == KEY_O)
		fractol->iteration *= (1 - fractol->change_rate);
	ft_arrow_keyboard_handler(keycode, fractol);
}

/**
 * --------------------------------------
 * Width and height after zooming
 * --------------------------------------
 * new_width = width * zoom_factor;
 * new_width = width * zoom_factor;
 * 
 * --------------------------------------
 * Zoomed distance
 * --------------------------------------
 * (scaled_mouse_x - fractol->min_x) * zoom_factor;
 * Note: 
 * 	- Min_x is always NEGATIVE (or to the LEFT of the mouse_x position)
 * 	- Max_x is always POSITIVE (or to the RIGHT of the mouse_x position)
 */
static inline void	ft_mouse_scroll_handler(
	int keycode,
	double s_mouse_x, double s_mouse_y,
	t_fractol *fractol)
{
	long double	new_width;
	long double	new_height;
	long double	zoom_factor;

	if (keycode == MOUSE_SCROLL_DOWN)
		zoom_factor = 1 + fractol->change_rate;
	else if (keycode == MOUSE_SCROLL_UP)
		zoom_factor = 1 - fractol->change_rate;
	fractol->zoom_ratio = zoom_factor;
	new_width = (fractol->max_x - fractol->min_x) * zoom_factor;
	new_height = (fractol->max_y - fractol->min_y) * zoom_factor;
	fractol->min_x = s_mouse_x - (s_mouse_x - fractol->min_x) * zoom_factor;
	fractol->max_x = fractol->min_x + new_width;
	fractol->min_y = s_mouse_y - (s_mouse_y - fractol->min_y) * zoom_factor;
	fractol->max_y = fractol->min_y + new_height;
}

int	ft_mouse_hook(
	int keycode,
	int mouse_x, int mouse_y,
	void *void_struct)
{
	t_fractol	*fractol;
	double		scaled_mouse_x;
	double		scaled_mouse_y;

	fractol = (t_fractol *)void_struct;
	scaled_mouse_x = ft_pixel_to_coord((long double)mouse_x, fractol, 1);
	scaled_mouse_y = ft_pixel_to_coord((long double)mouse_y, fractol, 0);
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
		ft_mouse_scroll_handler(
			keycode,
			scaled_mouse_x, scaled_mouse_y,
			fractol);
	return (0);
}
