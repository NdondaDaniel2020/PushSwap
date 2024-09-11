/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:17:04 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_data;

typedef struct s_size
{
	int	min;
	int	max;
}		t_size;

void	sa(t_data *data, int i);
void	sb(t_data *data, int i);
void	ss(t_data *data);

void	pa(t_data *data);
void	pb(t_data *data);

void	ra(t_data *data, int i);
void	rb(t_data *data, int i);
void	rr(t_data *data);

void	rra(t_data *data, int i);
void	rrb(t_data *data, int i);
void	rrr(t_data *data);

void	error(t_data *data);

void	lstdel_front(t_list **list);
void	clean_stack(t_data *data);

void	free_matrix(char **matrix);
void	extract_data(t_data *data, char **data_list);

void	check_dublicate(t_data *data, int num);
void	do_operation(t_data *data, char *comand);
void	check_size_number(t_data *data, char *num_in_char);
void	check_is_number(t_data *data, char *num_in_char);
void	chek_duplicate_in_matrix(char **spliting_num, t_data *data);

int		is_in_order(t_list *list);
int		valid_command(char *command);
int		*value_to_pointer(int value);

t_size	stack_max_and_min_value(t_list *list);

#endif