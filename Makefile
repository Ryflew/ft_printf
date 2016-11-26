# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 07:22:10 by vdarmaya          #+#    #+#              #
#    Updated: 2016/11/25 23:13:13 by vdarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC = ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strstr.c \
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlcat.c ft_putchar.c ft_putstr.c \
		ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strnew.c ft_strsub.c \
		ft_strsplit.c ft_strtrim.c ft_strclr.c ft_strmap.c ft_strdel.c \
		ft_memdel.c ft_strmapi.c ft_striter.c ft_striteri.c ft_strequ.c \
		ft_strnequ.c ft_memalloc.c ft_strjoin.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strrev.c \
		ft_puttabstr.c ft_memtaballoc.c ft_lstcount.c ft_lstaddend.c \
		ft_lstaddmid.c ft_putnstr.c

SRC_PRINTF = ft_printf.c ft_printf_flag.c ft_printf_parser.c

OBJ = $(SRC:.c=.o) $(SRC_PRINTF:.c=.o)

SRCDIR = ./src/

SRCPDIR = ./src/ft_printf/

OBJDIR = ./obj/

INCDIR = ./include/

SRCS = $(addprefix $(SRCDIR), $(SRC))

SRCSP = $(addprefix $(SRCPDIR), $(SRC_PRINTF))

OBJS = $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRCS) $(SRCSP) -I$(INCDIR)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
