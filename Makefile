# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 09:49:24 by eseveno           #+#    #+#              #
#    Updated: 2015/06/10 11:17:31 by eseveno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =			libft_malloc_$(HOSTTYPE).so

CC =			gcc $(FLAGS) $(INCLUDES)

LINK =			libft_malloc.so

LIBFT =			-L./libft -lft

LIB =			./libft/libft.a

INCLUDES =		-I./includes -I./libft/includes

SRC =			malloc.c show_alloc_mem.c concat.c free.c create.c

OBJ =			$(SRC:.c=.o)

FLAGS =			-Wall -Wextra -Werror

all:			$(LIB) $(NAME)
$(LIB):
				@echo "\033[32m[Make]\033[0m   " | tr -d '\n'
				@echo "\033[36m[libft]\033[0m Building libft... " | tr -d '\n'
				Make -C libft
$(NAME):		$(OBJ)
				@echo "\033[32m[Make]\033[0m   " | tr -d '\n'
				@echo "\033[36m[$(NAME)]\033[0m " | tr -d '\n'
				@echo "Building $(NAME)... " | tr -d '\n'
				@rm -f $(LINK)
				$(CC) -shared -o $(NAME) $(OBJ) $(LIBFT)
				@echo "\033[32m   -> \033[0m" | tr -d '\n'
				@echo "\033[36m$(NAME) \033[0m\033[32mcreated\033[0m"
				@ln -s $(NAME) $(LINK)
clean:
				Make -C libft clean
				@echo "\033[31m[clean] " | tr -d '\n'
				@echo "\033[36m[$(NAME)]\033[0m Remove ofiles"
				rm -f $(OBJ)
fclean:
				Make -C libft fclean
				rm -f $(OBJ)
				rm -f $(NAME)
				rm -f $(LINK)
				@echo "\033[31m[fclean] \033[36m[$(NAME)]\033[0m" | tr -d '\n'
				@echo " Remove ofiles & $(NAME)"
re:				fclean all
.PHONY:			all clean re fclean
.SILENT:
%.o:			%.c
				$(CC) -c $< -o $@