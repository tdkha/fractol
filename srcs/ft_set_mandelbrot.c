/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:54:28 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/23 21:23:56 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 *----------------------------------------------
 * arr[4] = {x, y, x2, y2}
 * arr[0] = x;
 * arr[1] = y;
 * arr[2] = x2 = x_squared;
 * arr[3] = y2 = y_squared;
 *----------------------------------------------
 */
static inline void	ft_set_var_mandelbrot(long double *arr)
{
	arr[0] = 0.0;
	arr[1] = 0.0;
	arr[2] = 0.0;
	arr[3] = 0.0;
}

int	ft_set_mandelbrot(t_fractol *fractol, int row, int col, int iter)
{
	long double	arr[4];
	long double	w;
	long double	x0;
	long double	y0;
	int			max_iter;

	ft_set_var_mandelbrot(&arr[0]);
	w = 0;
	x0 = ft_pixel_to_coord(col, fractol, 1);
	y0 = ft_pixel_to_coord(row, fractol, 0);
	max_iter = fractol->iteration;
	while ((arr[2] + arr[3] <= 4.0) && (iter < max_iter))
	{
		arr[0] = arr[2] - arr[3] + x0;
		arr[1] = w - arr[2] - arr[3] + y0;
		arr[2] = arr[0] * arr[0];
		arr[3] = arr[1] * arr[1];
		w = (arr[0] + arr[1]) * (arr[0] + arr[1]);
		if (arr[2] + arr[3] > 4.0)
			break ;
		iter++;
	}
	return (iter);
}
