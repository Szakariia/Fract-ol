# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 17:15:33 by szakaria          #+#    #+#              #
#    Updated: 2020/03/05 21:09:17 by szakaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror

_lCYAN = \x1b[96m
_lYELLOW = \x1b[93m
_lGREEN = \x1b[92m
_lBLUE = \x1b[94m
_RED = \x1b[31m
_BOLD = \x1b[1m
_END = \x1b[0m

LIB = libft/libft.a

FILE = burning_ship.c\
		julia.c\
		main.c\
		mandelbrot.c\
		menu_error.c

OFILE = burning_ship.o\
		julia.o\
		main.o\
		mandelbrot.o\
		menu_error.o

all: $(NAME)

$(NAME): $(OFILE)
		@make -C libft
		@gcc -o $(NAME) $(OFILE) $(LIB) -I ./minilibx -lmlx -framework OpenGL -framework Appkit
		@echo "\n$(_lGREEN) -> The FRACTOL was completed <-\n"

clean:
	@make -C libft clean
	@rm -rf $(OFILE)
	@echo "$(_lGREEN) > make clean $(_END)"

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(_lGREEN) > make fclean $(_END)"

re: fclean all
	@echo "$(_lGREEN) > make re $(_END)"
