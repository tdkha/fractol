/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:21:39 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/14 19:32:38 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../srcs/libft/libft.h"
# include "../srcs/mlx_linux/mlx.h"

typedef struct	s_fractol
{
	void			*mlx;
	void			*img;
	int				(*func)(struct s_fractol *factol, int row, int col);
	int 			precision;
	long double		min_x;
	long double		max_x;
	long double		min_y;
	long double		max_y;
		
}	t_fractol;




#endif