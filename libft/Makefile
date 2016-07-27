# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/11 13:00:14 by eseveno           #+#    #+#              #
#    Updated: 2015/06/01 17:44:37 by eseveno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

NAME		= libft.a

HEAD		= includes/libft.h

SRC			= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_itoa.c ft_strclr.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c \
ft_strnequ.c ft_strnew.c ft_strsplit.c ft_strsub.c ft_strtrim.c ft_memalloc.c \
ft_strdel.c ft_memdel.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c \
ft_lstdel.c ft_lstmap.c ft_getnbr.c ft_isdigitminp.c \
ft_strcpy_2d.c ft_printf.c ft_easy_print.c ft_hex_print.c ft_nbr_print.c\
ft_spaceonly.c ft_strdel2d.c ft_strlen2d.c ft_str_isdigit.c

OBJ			= $(SRC:.c=.o)

FLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ) $(HEAD)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			echo "\033[31mLibft dong_e.\033[0m"

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean re fclean

%.o:		%.c
			$(CC) $(CFLAGS) -I./includes $(OFLAGS) -c $< -o $@
