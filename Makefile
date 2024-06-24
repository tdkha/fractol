# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 19:34:49 by ktieu             #+#    #+#              #
#    Updated: 2024/06/24 11:29:22 by ktieu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -Ofast -flto -I ./includes
MLX			=	srcs/mlx_linux
LIBFT		=	srcs/libft

LIBS		= 	${MLX}/libmlx_Linux.a -ldl -lglfw -pthread -lm \
			${LIBFT}/libft.a

SRCS		=	./srcs/main.c \
				./srcs/ft_init.c \
				./srcs/ft_close.c  \
				./srcs/ft_frand.c  \
				./srcs/ft_complex.c \
				./srcs/ft_complex_extent.c \
				./srcs/ft_display.c \
				./srcs/ft_set_utils.c \
				./srcs/ft_set_mandelbrot.c \
				./srcs/ft_set_julia.c \
				./srcs/ft_hooks.c \
				./srcs/ft_color.c \
				./srcs/ft_mlx_pixel_put.c \
				./srcs/ft_pixel_to_coord.c

B_SRCS		=	./srcs/main.c \
				./srcs/ft_init.c \
				./srcs/ft_close.c  \
				./srcs/ft_frand.c  \
				./srcs/ft_complex.c \
				./srcs/ft_complex_extent.c \
				./srcs/ft_display.c \
				./srcs/ft_set_bonus.c \
				./srcs/ft_set_utils_bonus.c \
				./srcs/ft_set_mandelbrot.c \
				./srcs/ft_set_julia.c \
				./srcs/ft_hooks.c \
				./srcs/ft_color.c \
				./srcs/ft_mlx_pixel_put.c \
				./srcs/ft_pixel_to_coord.c

OBJDIR		=	obj
OFILES		=	$(addprefix $(OBJDIR)/, $(notdir ${SRCS:.c=.o}))
B_OFILES	=	$(addprefix $(OBJDIR)/, $(notdir ${B_SRCS:.c=.o}))

all: mandatory

mandatory: $(NAME)

bonus: .bonus

.libft:	
	@touch .libft
	${MAKE} -C ${LIBFT}

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) .libft
	${MAKE} -C ${MLX}
	$(CC) $(CFLAGS) $(OFILES) -L${LIBFT} -lft -L${MLX} -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
	@touch .mandatory
	@rm -f .bonus

.bonus: $(B_OFILES) .libft
	@touch .bonus
	${MAKE} -C ${MLX}
	$(CC) $(CFLAGS) $(B_OFILES) -L${LIBFT} -lft -L${MLX} -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
	@rm -f .mandatory

clean:
	${MAKE} -C ${LIBFT} clean
	rm -rf ${OBJDIR}
	@rm -f .bonus .mandatory .libft

fclean: clean
	${MAKE} -C ${LIBFT} fclean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
