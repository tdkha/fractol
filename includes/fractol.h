/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:21:39 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/17 00:04:15 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "./complex.h"
# include "../srcs/libft/libft.h"
# include "../srcs/mlx_linux/mlx.h"

# define WINDOW_W 800
# define WINDOW_H 800

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define KEY_ONE 49
# define KEY_TWO 50
# define KEY_THREE 51
# define KEY_FOUR 52
# define KEY_FIVE 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3
# define MOUSE_BTN 1
# define MOUSE_BTN_2 3
# define KEY_K 107

typedef enum e_set_type
{
	MANDELBROT,
	JULIA
}	t_set_type;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractol
{
	void			*mlx;
	t_img			img_struct;
	void			*window;
	t_set_type		type;
	int				iteration;
	int				zoom_ratio;
	long double		min_x;
	long double		max_x;
	long double		min_y;
	long double		max_y;
	int32_t			mouse_x;		
	int32_t			mouse_y;
	double			red;
	double			green;
	double			blue;
	t_complex_num	julia_values;
}	t_fractol;

/*+------------------------------------------------------------+*/
//	HELPER
/*+------------------------------------------------------------+*/

float	ft_frand(void);
int		ft_rand_color_map(int iteration, t_fractol *fractol);
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);

/*+------------------------------------------------------------+*/
//	FRACTOL STRUCT FUNCTIONS
/*+------------------------------------------------------------+*/

void	ft_fractol_init(int ac, char **av, t_fractol *fractol);
void	ft_close(t_fractol *fractol, int exit_code);
void	ft_close_print(t_fractol *fractol, int exit_code, char *msg);
void	ft_display(t_fractol *fractol);

/*+------------------------------------------------------------+*/
//	HOOKS
/*+------------------------------------------------------------+*/

int		ft_loop_hook(void *void_struct);
int		ft_keyboard_hook(int keycode, void *void_struct);
/*+------------------------------------------------------------+*/
//	SETS
/*+------------------------------------------------------------+*/

int		ft_set_mandelbrot(t_fractol *fractol, int row, int col, int iter);
int		ft_mandelbrot(t_fractol *stc, int row, int col);
#endif