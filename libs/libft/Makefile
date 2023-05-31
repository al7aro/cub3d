# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 18:44:21 by alfgarci          #+#    #+#              #
#    Updated: 2023/04/22 20:38:26 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=	src

SRCS	=	${SRC_DIR}/ft_atoi.c \
			${SRC_DIR}/ft_atof.c \
			${SRC_DIR}/ft_bzero.c \
			${SRC_DIR}/ft_calloc.c \
			${SRC_DIR}/ft_isalnum.c \
			${SRC_DIR}/ft_isalpha.c \
			${SRC_DIR}/ft_isascii.c \
			${SRC_DIR}/ft_isdigit.c \
			${SRC_DIR}/ft_isprint.c \
			${SRC_DIR}/ft_itoa.c \
			${SRC_DIR}/ft_memchr.c \
			${SRC_DIR}/ft_memcmp.c \
			${SRC_DIR}/ft_memcpy.c \
			${SRC_DIR}/ft_memmove.c \
			${SRC_DIR}/ft_memset.c \
			${SRC_DIR}/ft_putchar_fd.c \
			${SRC_DIR}/ft_putendl_fd.c \
			${SRC_DIR}/ft_putnbr_fd.c \
			${SRC_DIR}/ft_putstr_fd.c \
			${SRC_DIR}/ft_split.c \
			${SRC_DIR}/ft_strchr.c \
			${SRC_DIR}/ft_strdup.c \
			${SRC_DIR}/ft_strjoin.c \
			${SRC_DIR}/ft_striteri.c \
			${SRC_DIR}/ft_strlcat.c \
			${SRC_DIR}/ft_strlcpy.c \
			${SRC_DIR}/ft_strlen.c \
			${SRC_DIR}/ft_strmapi.c \
			${SRC_DIR}/ft_strncmp.c \
			${SRC_DIR}/ft_strnstr.c \
			${SRC_DIR}/ft_strrchr.c \
			${SRC_DIR}/ft_strtrim.c \
			${SRC_DIR}/ft_substr.c \
			${SRC_DIR}/ft_tolower.c \
			${SRC_DIR}/ft_toupper.c \
			${SRC_DIR}/ft_lstnew.c \
			${SRC_DIR}/ft_lstadd_front.c \
			${SRC_DIR}/ft_lstsize.c \
			${SRC_DIR}/ft_lstlast.c \
			${SRC_DIR}/ft_lstadd_back.c \
			${SRC_DIR}/ft_lstdelone.c \
			${SRC_DIR}/ft_lstclear.c \
			${SRC_DIR}/ft_lstiter.c \
			${SRC_DIR}/ft_lstmap.c \
			${SRC_DIR}/get_next_line.c \
			${SRC_DIR}/ft_printf_utils.c \
			${SRC_DIR}/ft_puthex.c \
			${SRC_DIR}/ft_putmem.c \
			${SRC_DIR}/ft_putunsig.c \
			${SRC_DIR}/ft_printf.c

OBJS 	=	${SRCS:.c=.o}

INC 	=	include/

CC	=	gcc -Wall -Wextra -Werror

NAME 	=	libft.a

.c.o:
	${CC} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean
