# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 21:57:05 by llacsivy          #+#    #+#              #
#    Updated: 2024/10/19 14:44:17 by daspring         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= miniRT
# CFLAGS			:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLXDOTA		:= ./MLX42/build/libmlx42.a

# LIBMLX42		:= ./MLX42/build/libmlx42.a -ldl -lglfw -lm
LIBMLX42		:= ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX42_URL		:= https://github.com/codam-coding-college/MLX42.git
# MLX42_VERSION	:= v2.4.0
# MLX42_VERSION	:= v2.3.4
MLX42_VERSION	:= v2.3.3

INCL			:= -I ./MLX42/include
DEPENDENCIES	:= 	./includes/color.h \
					./includes/maths.h \
					./includes/miniRT.h \
					./includes/objects.h \
					./includes/ray.h

LIBFTDOTA		:= libft/libft.a
SRCS			:= 	miniRT.c \
					sources/ray/ray.c \
					sources/canvas/canvas.c \
					sources/canvas/color.c \
					sources/shapes/camera.c \
					sources/shapes/plane.c \
					sources/maths/angle_utils.c \
					sources/maths/tuple_1.c \
					sources/maths/tuple_2.c \
					sources/maths/tuple_3.c \
					sources/dev_print_tuple.c

OBJS			:=	${SRCS:.c=.o}

$(NAME): $(LIBMLXDOTA) $(LIBFTDOTA) $(OBJS)
	@echo "Compiling miniRT ..."
	cc $(OBJS) $(LIBMLX42) $(LIBFTDOTA) $(INCL) -o $(NAME)
	# cc $(OBJS) $(LIBMLX42) $(LIBFTDOTA) /users/llacsivy/LeakSanitizer/liblsan.dylib $(INCL) -o $(NAME)
	
debug: $(LIBMLXDOTA) $(LIBFTDOTA) $(OBJS)
	@echo "Compiling miniRT ..."
	cc -g $(OBJS) $(LIBMLX42) $(LIBFTDOTA) $(INCL) -o debug
	
%.o: %.c $(DEPENDENCIES)
	cc -g $(CFLAGS) -c $< -o $@

all: $(LIBMLXDOTA) $(NAME)

$(LIBMLXDOTA):
	@echo "Making MLX42..."
	git clone $(MLX42_URL) && cd ./MLX42 && git checkout tags/$(MLX42_VERSION)
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

.PHONY: all clean fclean re debug
