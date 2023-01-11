# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 15:39:30 by ralopez-          #+#    #+#              #
#    Updated: 2022/10/11 14:18:23 by ralopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = libft/ft_isalpha.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
        libft/ft_strlen.c libft/ft_isdigit.c libft/ft_bzero.c libft/ft_toupper.c \
        libft/ft_tolower.c libft/ft_memcpy.c libft/ft_atoi.c libft/ft_strlcpy.c \
        libft/ft_calloc.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c\
        libft/ft_strrchr.c libft/ft_strnstr.c libft/ft_strlcat.c libft/ft_strdup.c \
        libft/ft_strchr.c libft/ft_memmove.c libft/ft_substr.c libft/ft_strjoin.c \
        libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
        libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
        libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_memset.c \
        libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c \
        libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c \
        libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c \
        libft/ft_split_upgrade.c libft/ft_split_upgrade_aux.c libft/ft_strcmp.c \
        libft/ft_aux_disc.c  libft/ft_printf.c  libft/ft_show_pointer.c \
        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		ft_pipex_aux.c ft_enviroment.c ft_files.c ft_child.c ft_errors.c ft_pipes.c pipex.c 

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
AR = ar -rcs
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY : all clean fclean re
