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
		push_swap_utils.c \
		push_swap_clacifier.c
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
	$(CC) $(RF) $(LIBFT) -o ./run

$(LIBFT):
	make bonus -C $(PLIBFT)

n:
	python3 -m norminette ./*.c ./*.h
	python3 -m norminette ./libft/*.c ./libft/*.h

clean:
	@/bin/rm -f $(OBJ)

fclean:	clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(RUN)
	@make fclean -C $(PLIBFT)
	@make clean -C $(PMLX)

re:	fclean all

.PHONY: all clean fclean re
