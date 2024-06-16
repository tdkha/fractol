/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:26:02 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/16 23:47:53 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_rand_color_map(int iteration, t_fractol *fractol)
{
	double	i;
	int		r;
	int		g;
	int		b;
	int		esc_ratio;

	i = (double)iteration / fractol->iteration;
	esc_ratio = i * 790;
	r = (int)(fractol->red * esc_ratio) % 255;
	g = (int)(fractol->green * esc_ratio) % 255;
	b = (int)(fractol->blue * esc_ratio) % 255;
	return (create_trgb(255, r, g, b));
}
