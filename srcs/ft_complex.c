/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:13:42 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/24 11:12:13 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/complex.h"

inline t_complex_num	ft_complex_sum(t_complex_num c1, t_complex_num c2)
{
	t_complex_num	res;

	res.real = c1.real + c2.real;
	res.imaginary = c1.imaginary + c2.imaginary;
	return (res);
}

inline t_complex_num	ft_complex_subtract(t_complex_num c1, t_complex_num c2)
{
	t_complex_num	res;

	res.real = c1.real - c2.real;
	res.imaginary = c1.imaginary - c2.imaginary;
	return (res);
}

inline t_complex_num	ft_complex_multiply(t_complex_num c1, t_complex_num c2)
{
	t_complex_num	res;

	res.real = c1.real * c2.real;
	res.imaginary = c1.imaginary * c2.imaginary;
	return (res);
}

inline t_complex_num	ft_complex_divide(t_complex_num c1, t_complex_num c2)
{
	t_complex_num	result;
	long double		denom;

	denom = c2.real * c2.real + c2.imaginary * c2.imaginary;
	result.real = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denom;
	result.imaginary = (c1.imaginary * c2.real
			- c1.real * c2.imaginary) / denom;
	return (result);
}
