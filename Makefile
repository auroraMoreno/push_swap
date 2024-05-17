# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 08:57:17 by aumoreno          #+#    #+#              #
#    Updated: 2024/05/15 18:12:50 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra 

SRCS = main.c # luego add el fichero operations.c o algo asi para las operations: push, swap, rotate y reverse 

# hay que add el printf: 

FT_PRINTF_PATH = ft_printf/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(FT_PRINTF_PATH)

# Without this assignment, 
# you would need to manually list all the object files in the linker command, 
# which can be error-prone and tedious, especially in larger projects.

OBJS = $(SRCS:.c=.o) # needed for linking the final executable 

all : $(EXEC)

$(EXEC): $(OBJS)

$(EXEC): $(OBJS)
	@make -C $(FT_PRINTF_PATH) --silent
	@$(CC) $(CFLAGS) $(SRCS) -o $(EXEC) -I./ft_printf -L./ft_printf -l ftprintf


clean:
	rm -f $(OBJS)
	@make -C $(FT_PRINTF_PATH) clean --silent

fclean:  clean
	rm -f $(EXEC)
	rm -f $(OBJS)
	@make -C $(FT_PRINTF_PATH) fclean --silent


re: fclean all

.PHONY: all clean fclean re 