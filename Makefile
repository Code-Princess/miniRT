# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linda <linda@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2025/02/23 15:07:31 by linda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			:= miniRT
CFLAGS			:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLXDOTA		:= ./MLX42/build/libmlx42.a

LIBMLX42		:= ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX42_URL		:= https://github.com/codam-coding-college/MLX42.git
Commit_Hash		:= 154e0c396d104b72582b7c6ea26b0fb777a0fc2f

INCL			:= -I ./MLX42/include
DEPENDENCIES	:= 	./includes/color.h \
					./includes/maths.h \
					./includes/miniRT.h \
					./includes/objects.h \
					./includes/ray.h

LIBFTDOTA		:= libft/libft.a
SRCS			:= 	miniRT.c \
					sources/hooks/hooks.c \
					sources/parser/parser.c \
					sources/parser/parser_init_fcts_1.c \
					sources/parser/parser_init_fcts_2.c \
					sources/parser/parser_init_fcts_3.c \
					sources/parser/parser_init_fcts_4.c \
					sources/parser/parser_init_fcts_5.c \
					sources/parser/parse_amb_light.c \
					sources/parser/parse_camera.c \
					sources/parser/parse_light.c \
					sources/parser/parse_plane.c \
					sources/parser/parse_sphere.c \
					sources/parser/parse_cylinder.c \
					sources/ray/ray.c \
					sources/canvas/canvas.c \
					sources/canvas/canvas_utils.c \
					sources/canvas/color.c \
					sources/canvas/lighting.c \
					sources/canvas/shadow.c \
					sources/canvas/get_fcts.c \
					sources/shapes/camera.c \
					sources/shapes/plane.c \
					sources/shapes/sphere.c \
					sources/shapes/cylinder.c \
					sources/shapes/cylinder_utils.c \
					sources/shapes/cylinder_hitpoint.c \
					sources/maths/angle_utils.c \
					sources/maths/tuple_1.c \
					sources/maths/tuple_2.c \
					sources/maths/tuple_3.c \
					sources/utilities/ft_printf_error.c \
					sources/utilities/exit_fcts.c \
					sources/free/free_fcts.c

OBJS			:=	${SRCS:.c=.o}

$(NAME): $(LIBMLXDOTA) $(LIBFTDOTA) $(OBJS)
	@echo "Compiling miniRT ..."
	cc $(CFLAGS) $(OBJS) $(LIBMLX42) $(LIBFTDOTA) $(INCL) -o $(NAME)

%.o: %.c $(DEPENDENCIES)
	cc $(CFLAGS) -c $< -o $@

all: $(LIBMLXDOTA) $(NAME)

$(LIBMLXDOTA):
	@echo "Making MLX42..."
	git clone $(MLX42_URL) && cd ./MLX42 && git checkout $(Commit_Hash)
	cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

$(LIBFTDOTA):
	$(MAKE) -C libft/

clean:
	@echo "Cleaning object files..."
	$(MAKE) clean -C libft/
	rm -f $(OBJS)
	rm -rf ./MLX42/build
	rm -rf ./MLX42

fclean : clean
	@echo "Cleaning miniRT"
	$(MAKE) fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
