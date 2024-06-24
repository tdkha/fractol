/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_extent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:49:05 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/24 11:12:09 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/complex.h"

inline t_complex_num	ft_complex_multiply_constant(long double constant, t_complex_num num)
{
	t_complex_num	res;

	res.real = constant * num.real;
	res.imaginary = constant * num.imaginary;
	return (res);
}

inline t_complex_num	ft_complex_squared(t_complex_num num)
{
	t_complex_num	res;

	res.real = (num.real * num.real) - (num.imaginary * num.imaginary);
	res.imaginary = 2 * num.real * num.imaginary;
	return (res);
}

inline t_complex_num	ft_complex_cube_minus(t_complex_num num)
{
	t_complex_num	res;

	res.real = 
		(num.real * num.real * num.real)
		- (3 * (num.real * num.imaginary * num.imaginary));
	res.imaginary = 
		(-1) *(num.imaginary * num.imaginary * num.imaginary)
		+ (3 * (num.real * num.real * num.imaginary));
	return (res);
}