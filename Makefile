# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 08:57:17 by aumoreno          #+#    #+#              #
#    Updated: 2024/07/29 22:11:03 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c general_utils.c stacks_utils.c error_utils.c push_operations.c \
		swap_operations.c rotate_operations.c reverse_rotate_operations.c \
		algorithm_three.c algorithm_four.c algorithm_five.c alg_utils.c \
		algorithm.c chunk_generator.c

FT_PRINTF_PATH = ft_printf/
LIBFT_PATH = libft/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_PATH)

          
OBJS = $(SRCS:.c=.o)

all : $(EXEC)

$(EXEC): $(OBJS)

$(EXEC): $(OBJS)
	@make -C $(FT_PRINTF_PATH) --silent
	@make -C $(LIBFT_PATH) --silent
	@$(CC) $(CFLAGS) $(SRCS) -o $(EXEC) -I./libft -L./libft -lft -I./ft_printf -L./ft_printf -l ftprintf


clean:
	rm -f $(OBJS)
	@make -C $(FT_PRINTF_PATH) clean --silent

fclean:  clean
	rm -f $(EXEC)
	rm -f $(OBJS)
	@make -C $(FT_PRINTF_PATH) fclean --silent
	@make -C $(LIBFT_PATH) fclean --silent



re: fclean all

.PHONY: all clean fclean re 