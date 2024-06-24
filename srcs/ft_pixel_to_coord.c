/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_to_coord.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:23:37 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/23 21:24:12 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

long double	ft_pixel_to_coord(
	long double value,
	t_fractol *fractol,
	int is_x_axis)
{
	long double	scale_x;
	long double	scale_y;

	scale_x = (fractol->max_x - fractol->min_x) / (long double)WINDOW_W;
	scale_y = (fractol->max_y - fractol->min_y) / (long double)WINDOW_H;
	if (!is_x_axis)
		return ((value * scale_y) + fractol->min_y);
	else
		return ((value * scale_x) + fractol->min_x);
}
