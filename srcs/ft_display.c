/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:54:06 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/23 21:45:13 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static inline int ft_get_set(t_fractol *fractol, int row, int col)
{
	if (fractol->type == MANDELBROT)
	{
		return (ft_set_mandelbrot(fractol, row, col, 0));
	}
	else if (fractol->type ==JULIA)
	{
		return (ft_set_julia(fractol, row, col));
	}
}

void	ft_display(t_fractol *fractol)
{
	int	res;
	int	row;
	int	col;
	int	color;

	row = 0;
	col = 0;
	while (row < WINDOW_H)
	{
		col = 0;
		while (col < WINDOW_W)
		{
			res = ft_get_set(fractol, row, col);
			color = ft_rand_color_map(res, fractol);
			ft_mlx_pixel_put(&fractol->img_struct, col, row, color);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(
		fractol->mlx, fractol->window,
		fractol->img_struct.img, 0, 0);
}
