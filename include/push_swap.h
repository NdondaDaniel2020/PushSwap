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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>

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

typedef struct s_bool_num
{
	int	valid;
	int	num;
}		t_bool_num;

typedef struct s_operation
{
	int		value;
	char	*operation_to_do;
}			t_operation;

void		extract_data(t_data *data, char **data_list);
void		check_dublicate(t_data *data, int num);
void		lstdel_front(t_list **list);
void		free_matrix(char **matrix);
void		clean_stack(t_data *data);
void		init_data(t_data *data);

void		case_3(t_data *data);
void		case_4(t_data *data);
void		case_5(t_data *data, t_size size);
void		clacifier_point(t_data *data);

void		sa(t_data *date, int i);
void		sb(t_data *data, int i);
void		ss(t_data *data);

void		pa(t_data *data);
void		pb(t_data *data);

void		ra(t_data *data, int i);
void		rb(t_data *data, int i);
void		rr(t_data *data);

void		rra(t_data *data, int i);
void		rrb(t_data *data, int i);
void		rrr(t_data *data);

void		error(t_data *data);

void		free_operation(t_operation *op);
void		check_is_number(t_data *data, char *num_in_char);
void		check_size_number(t_data *data, char *num_in_char);
void		free_all_operation(t_operation *op_a, t_operation *op_b);
void		chek_duplicate_in_matrix(char **spliting_num, t_data *data);

int			is_in_order(t_list *list);
int			opcmp(char *s1, char *s2);
int			is_in_order_des(t_list *list);
int			*value_to_pointer(int value);
int			get_pos_in_stack(int value, t_list *stack);

char		*ft_charjoin_free(char *s1, char c, int l2);
char		*join_string_operation_element(char *s_a, char *s_b);

t_data		*cpy_data(t_data *data);

t_size		stack_max_and_min_value(t_list *list);

t_bool_num	*get_predecessor(t_list *list, int value);

t_operation	*init_operation(void);
t_operation	*send_max_to_the_top_of_b(t_data *data);
t_operation	*count_operation_to_b(int value, t_data *data);
t_operation	*count_operation_to_a(int value, t_data *data);
t_operation	*get_the_shortest_operation_a_to_b(t_data *data);
t_operation	*get_the_shortest_operation_b_to_a(t_data *data);
t_operation	*join_each_element(t_operation *op, char *new_op);
t_operation	*join_operation_to_do(t_operation *op_a, t_operation *op_b);

#endif