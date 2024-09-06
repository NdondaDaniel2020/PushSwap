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
RUN = ./push_swap
NAME = $(RUN).a
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
		push_swap_utils_1.c \
		push_swap_utils_2.c \
		push_swap_utils_3.c

OBJ = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror
PLIBFT = ./libft
LIBFT = $(PLIBFT)/libft.a

RF = rascunho.c

all:	$(NAME)

$(NAME):	$(LIBFT)
	@$(CC) $(FLAGS) -c $(FILES)
	@ar rc $(NAME) $(OBJ)
	@$(CC) $(FLAGS) $(NAME) $(LIBFT) -o $(RUN)

run: $(NAME)
	@make clean
	@$(CC) $(FLAGS) $(NAME) $(LIBFT) -o $(RUN)

e:
	$(CC) $(FLAGS) $(FILES) $(LIBFT) -o $(RUN)

r:
	$(CC) $(RF) $(LIBFT) -o ./r

$(LIBFT):
	make bonus -C $(PLIBFT)

clean:
	@/bin/rm -f $(OBJ)

fclean:	clean
	@/bin/rm -f ./r
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(RUN)
	@make fclean -C $(PLIBFT)

re:	fclean all

.PHONY: all run e r clean fclean re
