# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 01:32:20 by nmatondo          #+#    #+#              #
#    Updated: 2024/08/07 16:44:49 by nmatondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = ./push_swap
BONUS = ./checker_linux
SRC = ./src/
INCLUDE = ./include

FILES = push_swap.c \
		push_swap_case.c \
		push_swap_clacifier_1.c \
		push_swap_clacifier_2.c \
		push_swap_clacifier_3.c \
		push_swap_clacifier_point.c \
		push_swap_count_operation.c \
		push_swap_join_operation.c \
		push_swap_operating_cost_1.c \
		push_swap_operating_cost_2.c \
		push_swap_send_max_to_top.c \
		push_swap_shortest_operation.c \
		push_swap_utils_1.c \
		push_swap_utils_2.c \
		push_swap_utils_3.c

SRC_FILES = $(addprefix $(SRC),$(FILES))
OBJ = $(FILES:.c=.o)


FLAGS = -Wall -Wextra -Werror
PLIBFT = ./libft
LIBFT = $(PLIBFT)/libft.a

RF = rascunho.c

all:	$(NAME)

$(NAME):	$(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_FILES) -I$(INCLUDE)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -I$(INCLUDE) -o $(NAME)


# bonus:

run: $(NAME)
	@make clean
	@$(CC) $(FLAGS) $(NAME) $(LIBFT) -o $(NAME)

e:
	$(CC) $(FLAGS) $(FILES) $(LIBFT) -o $(NAME)

r:
	$(CC) $(RF) $(LIBFT) -o ./r

$(LIBFT):
	make bonus -C $(PLIBFT)

clean:
	@/bin/rm -f $(OBJ)
	make clean -C $(PLIBFT)

fclean:	clean
	@/bin/rm -f ./r
	@/bin/rm -f $(NAME)
	@make fclean -C $(PLIBFT)

re:	fclean all

.PHONY: all bonus run e r clean fclean re
