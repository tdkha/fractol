/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:56:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/23 21:24:49 by ktieu            ###   ########.fr       */
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

t_complex_num	ft_complex_squared(t_complex_num num);

#endif