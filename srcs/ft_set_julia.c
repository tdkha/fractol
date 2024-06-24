/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:53:57 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/24 10:18:03 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_set_julia(t_fractol *fractol, int row, int col)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;

	i = 0;
	z.real = ft_pixel_to_coord(col, fractol, 1);
	z.imaginary = ft_pixel_to_coord(row, fractol, 0);
	c.real = fractol->julia_values.real;
	c.imaginary = fractol->julia_values.imaginary;
	while (i < fractol->iteration)
	{
		z = ft_complex_sum(ft_complex_squared(z), c);
		if (((z.real * z.real) + (z.imaginary * z.imaginary)) > 4)
		{
			break ;
		}
		i++;
	}
	return (i);
}
