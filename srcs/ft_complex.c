/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:13:42 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/23 21:22:33 by ktieu            ###   ########.fr       */
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

inline t_complex_num	ft_complex_squared(t_complex_num num)
{
	t_complex_num	res;

	res.real = (num.real * num.real) - (num.imaginary * num.imaginary);
	res.imaginary = 2 * num.real * num.imaginary;
	return (res);
}
