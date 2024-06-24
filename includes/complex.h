/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:56:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/24 11:12:28 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	long double	real;
	long double	imaginary;
}	t_complex_num;

t_complex_num	ft_complex_sum(t_complex_num c1, t_complex_num c2);

t_complex_num	ft_complex_subtract(t_complex_num c1, t_complex_num c2);

t_complex_num	ft_complex_multiply(t_complex_num c1, t_complex_num c2);

t_complex_num	ft_complex_multiply_constant(
					long double constant, t_complex_num num);

t_complex_num	ft_complex_divide(t_complex_num a, t_complex_num b);

t_complex_num	ft_complex_squared(t_complex_num num);

t_complex_num	ft_complex_cube_minus(t_complex_num num);

#endif