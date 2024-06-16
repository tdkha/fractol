/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:13:42 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/15 16:29:59 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/complex.h"

t_complex_num	ft_complex_sum(t_complex_num c1, t_complex_num c2)
{
	t_complex_num	res;

	res.real = c1.real + c2.real;
	res.imaginary = c1.imaginary + c2.imaginary;
	return (res);
}

t_complex_num	ft_complex_subtract(t_complex_num c1, t_complex_num c2)
{
	t_complex_num	res;

	res.real = c1.real - c2.real;
	res.imaginary = c1.imaginary - c2.imaginary;
	return (res);
}

t_complex_num	ft_complex_multiply(t_complex_num c1, t_complex_num c2)
{
	t_complex_num	res;

	res.real = c1.real * c2.real;
	res.imaginary = c1.imaginary * c2.imaginary;
	return (res);
}
