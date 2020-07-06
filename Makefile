# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suahn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 16:44:42 by suahn             #+#    #+#              #
#    Updated: 2020/07/06 17:45:27 by suahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_putnbr_base.c \
	  ft_treat_digit.c \
	  ft_treat_flag.c \
	  ft_init.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_printf.c \
	  ft_mallen.c \
	  ft_comb_minus_p.c \
	  ft_comb_minus_int.c \
	  ft_comb_minus_u.c \
	  ft_comb_minus_x.c \
	  ft_comb_minus_xx.c \
	  ft_comb_zero.c \
	  ft_comb_zero_int.c \
	  ft_comb_zero_u.c \
	  ft_comb_zero_x.c \
	  ft_comb_zero_xx.c \
	  print_pointer.c \
	  print_percent.c \
	  print_di.c \
	  print_x.c \
	  print_xx.c \
	  print_s.c \
	  print_c.c \
	  print_u.c

HEADER = includes
DIR_S = srcs
DIR_O = temporary

SRCS = $(addprefix ${DIR_S}/, ${SRC})

OBJS = $(addprefix ${DIR_O}/, ${SRC:.c=.o})

LIBFT = libft
CC = gcc
C = clang
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
