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
BONUS = ./checker
SRC = ./src/
BONUS_DIR = ./bonus/
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
		push_swap_shortest_operation.c \
		push_swap_utils_1.c \
		push_swap_utils_2.c \
		push_swap_utils_3.c \
		push_swap_utils_4.c 

SRC_FILES = $(addprefix $(SRC),$(FILES))
OBJ = $(FILES:.c=.o)


BFILES = checker.c \
		 checker_clacifier_1.c \
		 checker_clacifier_2.c \
		 checker_clacifier_3.c \
		 checker_do_operation.c \
		 checker_utils_1.c \
		 checker_utils_2.c \
		 checker_utils_3.c \
		 checker_utils_4.c 

SRC_BFILES = $(addprefix $(BONUS_DIR),$(BFILES))
BOBJ = $(BFILES:.c=.o)


FLAGS = -Wall -Wextra -Werror
PLIBFT = ./libft
LIBFT = $(PLIBFT)/libft.a

RF = rascunho.c

all:	$(NAME)

$(NAME):	$(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_FILES) -I$(INCLUDE)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -I$(INCLUDE) -o $(NAME)

bonus:	$(BONUS)

$(BONUS):	$(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_BFILES) -I$(INCLUDE)
	@$(CC) $(FLAGS) $(BOBJ) $(LIBFT) -I$(INCLUDE) -o $(BONUS)

$(LIBFT):
	make bonus -C $(PLIBFT)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(BOBJ)
	make clean -C $(PLIBFT)

fclean:	clean
	@/bin/rm -f ./r
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(BONUS)
	@make fclean -C $(PLIBFT)

re:	fclean all

.PHONY: all bonus r clean fclean re
