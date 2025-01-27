# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 10:59:59 by gudoyle           #+#    #+#              #
#    Updated: 2024/11/27 08:27:38 by gudoyle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
CC 				= gcc
RM				= rm -f

CFLAGS 			= -Wall -Wextra -Werror -I.

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
					ft_putchar_pf.c ft_putnbr_pf.c ft_putstr_pf.c ft_printf.c ft_putnbr_u_pf.c \
					ft_puthex_pf.c ft_putnbr_base_pf.c ft_putptr_pf.c get_next_line.c
OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				

clean:
				$(RM) $(OBJS)


fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus