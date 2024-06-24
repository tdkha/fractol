/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:26:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/24 11:12:35 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * z[n+1] = z[n]- (p(z[n]) / p'(z[n])) 
 * p(x) = z^3 - 1
 * p'(x) = 3(z^2)
 * a = 1 + 0i (complex number)
 */
int	ft_set_newton(t_fractol *fractol, int row, int col)
{
	t_complex_num	z;
	t_complex_num	p;
	t_complex_num	p_derivative;
	t_complex_num	one;
	int				i;
	
	z.real = ft_pixel_to_coord(col, fractol, 1);
	z.imaginary = ft_pixel_to_coord(row, fractol, 0);
	one.real = 1;
	one.imaginary = 0;
	i = 0;
	while (i < fractol->iteration)
	{
		p = ft_complex_subtract(ft_complex_cube_minus(z), one);
		p_derivative = ft_complex_multiply_constant(3, ft_complex_squared(z));
		z = ft_complex_subtract(z, ft_complex_divide(p, p_derivative));
		if ((p.real * p.real + p.imaginary * p.imaginary) < 0.001)
			break ;
		i++;
	}
	return (i);
}