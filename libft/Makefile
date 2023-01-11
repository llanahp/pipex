# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 15:39:30 by ralopez-          #+#    #+#              #
#    Updated: 2022/09/24 15:58:17 by ralopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_isdigit.c ft_bzero.c ft_toupper.c ft_tolower.c ft_memcpy.c \
	ft_atoi.c ft_strlcpy.c ft_calloc.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
	ft_strrchr.c ft_strnstr.c ft_strlcat.c ft_strdup.c ft_strchr.c \
	ft_memmove.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_memset.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
	ft_aux_disc.c ft_show_pointer.c ft_printf.c ft_split_upgrade.c ft_split_upgrade_aux.c \
	ft_strcmp.c

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
AR = ar -rcs
NAME_B = .file_shadow
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY : all clean fclean re 