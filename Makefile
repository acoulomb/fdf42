# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 22:08:39 by acoulomb          #+#    #+#              #
#    Updated: 2018/05/26 16:52:08 by acoulomb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

#BINARIES:
CC          = /usr/bin/clang
RM          = /bin/rm
MAKE        = /usr/bin/make

#LIBFT:
LFTPATH     = ./libft
LIBFT       = $(LFTPATH)/libft.a

#LIBMLX
MLX_FLAGS	= -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

#FLAGS:
CC = clang
FLAGS = -Wall -Wextra -Werror
LDFLAGS = -L $(LFTPATH) -lft $(MLX_FLAGS)

#EXECUTABLE:
NAME = fdf

#SRCS:
SRCS =	main.c \
		ft_projection.c \
		ft_putpixel.c \
		ft_draw_line.c \
		ft_read_file.c \
		ft_init.c \
		ft_key.c \
		ft_exit.c \
		ft_image.c \
		ft_color.c \

#OBJ:
OBJS = $(SRCS:.c=.o)

#HEADERS:
HEADS =	fdf.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(LDFLAGS) -o $@ $^
	@echo compilation : ok

%.o: %.c $(HEADS)
	@$(CC) -c $(FLAGS) -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LFTPATH)
	@echo compilation libft : ok

clean:
	@$(MAKE) -C $(LFTPATH) clean
	@$(RM) -f $(OBJS)
	@echo clean : ok

fclean: clean
	@$(MAKE) -C $(LFTPATH) fclean
	@$(RM) -rf $(NAME)
	@echo fclean : ok

cleanlib:
	$(MAKE) clean -C $(LFTPATH)
	@echo libft clean : ok

re: fclean all

g: re $(OBJS)
	$(CC) $(FLAGS) -g $(SRCS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

.PHONY = re all clean fclean g