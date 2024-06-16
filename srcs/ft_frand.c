/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:44:57 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/16 23:52:19 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float	ft_frand(void)
{
	static unsigned long	next;

	next = next * 1103515245 + 12345;
	return ((float)((next / 65536) % 32767) / (float)32767);
}

/* RAND_MAX assumed to be 32767. */