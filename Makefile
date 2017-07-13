# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 14:35:56 by rle               #+#    #+#              #
#    Updated: 2017/05/16 15:51:55 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJS = $(addprefix ./srcs/, \
			$(addsuffix .o, \
				main \
				get_map \
				get_map_help \
				let_it_go \
				bresenham_alg \
				draw_map \
				init \
				key_functs \
			) \
		)

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -L $(MLXLIB) -framework OpenGL -framework AppKit

CC = @gcc

INCLUDES = -I ./includes -I ./libft/includes -I ./minilibx_macos

LIB = ./libft

MLXLIB = ./minilibx_macos

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIB)/libft.a $(MLXLIB)/libmlx.a $(OBJS) $(INCLUDES) -o $(NAME)
	@echo "\x1B[31mFDF made\x1B[0m"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIB): force
	@make -C $(LIB)
	@make -C $(MLXLIB)

force: 
	@true

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIB)
	@make clean -C $(MLXLIB)
	@echo "\x1B[34m~~~clean~~~\x1B[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
