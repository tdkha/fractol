# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 19:34:49 by ktieu             #+#    #+#              #
#    Updated: 2024/06/16 23:16:40 by ktieu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	cc

CFLAGS		=	-Ofast -flto -I ./includes
MLX			=	srcs/mlx_linux
LIBFT		=	srcs/libft

LIBS		= 	${MLX}/libmlx_Linux.a -ldl -lglfw -pthread -lm \
			${LIBFT}/libft.a

SRCS		=	./srcs/main.c \
				./srcs/ft_init.c \
				./srcs/ft_close.c  \
				./srcs/ft_frand.c  \
				./srcs/ft_complex.c \
				./srcs/ft_display.c \
				./srcs/ft_set_mandelbrot.c \
				./srcs/ft_hooks.c \
				./srcs/ft_color.c \
				./srcs/ft_mlx_pixel_put.c

B_SRCS		=	./srcs/main.c \
				./srcs/ft_init.c \
				./srcs/ft_close.c  \
				./srcs/ft_frand.c  \
				./srcs/ft_complex.c \
				./srcs/ft_display.c \
				./srcs/ft_set_mandelbrot.c \
				./srcs/ft_hooks.c \
				./srcs/ft_color.c \
				./srcs/ft_mlx_pixel_put.c

OBJDIR		=	obj
OFILES		=	$(addprefix $(OBJDIR)/, $(notdir ${SRCS:.c=.o}))
B_OFILES	=	$(addprefix $(OBJDIR)/, $(notdir ${B_SRCS:.c=.o}))

all: mandatory

mandatory: $(NAME)

bonus: .bonus

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	${MAKE} -C ${LIBFT}
	${MAKE} -C ${MLX}
	$(CC) $(OFILES) -L${LIBFT} -lft -L${MLX} -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
	@touch .mandatory
	@rm -f .bonus

.bonus: $(B_OFILES)
	${MAKE} -C ${LIBFT}
	${MAKE} -C ${MLX}
	$(CC) $(CFLAGS) -o $(NAME) $(B_OFILES) $(LIBS) -flto
	@touch .bonus
	@rm -f .mandatory

clean:
	${MAKE} -C ${LIBFT} clean
	rm -rf ${OBJDIR}
	@rm -f .bonus .mandatory

fclean: clean
	${MAKE} -C ${LIBFT} fclean
	rm -rf ${NAME}
	@rm -f .bonus .mandatory

re: fclean all

.PHONY: all clean fclean re bonus
