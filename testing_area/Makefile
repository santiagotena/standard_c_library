# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 14:26:53 by stena-he          #+#    #+#              #
#    Updated: 2022/05/26 15:31:46 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libft.a

CCFLAGS = -Wall -Wextra -Werror

SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c

OUT = ${SRC:%.c=%.o}

${NAME}: all

all:
	gcc -c ${CCFLAGS} ${SRC}
	ar rcs ${NAME} ${OUT}

clean:
	rm -f ${OUT}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean clean all