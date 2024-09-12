/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_shortest_operation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pos_value_pair	pos_value_in_stacks(t_data *data, t_list *aux)
{
	int					size_stack[2];
	t_pos_value_pair	pair;
	t_bool_num			*predecessor;

	size_stack[0] = ft_lstsize(data->stack_a);
	size_stack[1] = ft_lstsize(data->stack_b);
	pair.a.value = *(int *)aux->content;
	pair.a.pos = get_pos_in_stack(pair.a.value, data->stack_a);
	predecessor = get_predecessor(data->stack_b, pair.a.value);
	pair.b.value = predecessor->num;
	pair.b.pos = get_pos_in_stack(pair.b.value, data->stack_b);
	if (pair.b.pos == -1)
	{
		pair.b.value = stack_max_and_min_value(data->stack_b).max;
		pair.b.pos = get_pos_in_stack(pair.b.value, data->stack_b);
	}
	if (pair.a.pos > (size_stack[0] / 2))
		pair.a.pos = size_stack[0] - pair.a.pos;
	if (pair.b.pos > (size_stack[1] / 2))
		pair.b.pos = size_stack[1] - pair.b.pos;
	free(predecessor);
	return (pair);
}

static t_operation	*join_free_operation(t_operation *op_a, t_operation *op_b)
{
	t_operation	*join;
	t_operation	*operation_to_do_a;
	t_operation	*operation_to_do_b;

	operation_to_do_a = count_operation_to_a(value, data);
	operation_to_do_b = count_operation_to_b(value, data);
    join = join_operation_to_do(operation_to_do_a, operation_to_do_b);
	free_operation(op_a);
	free_operation(op_b);
	return (join);
}

t_operation	*get_the_shortest_operation_a_to_b(t_data *data)
{
	int					i;
	t_list				*aux;
	t_pos_value_pair	pair;
	t_pos_value_pair	min_pair;

	i = 0;
	aux = data->stack_a;
	while (aux)
	{
		pair = pos_value_in_stacks(data, aux);
		if (i == 0 || ((pair.a.pos + pair.b.pos) < (min_pair.a.pos + min_pair.b.pos)))
		{
			min_pair.a.pos = pair.a.pos;
			min_pair.b.pos = pair.b.pos;
			min_pair.a.value = pair.a.value;
			min_pair.b.value = pair.b.value;
		}
		aux = aux->next;
		i++;
	}
	return ();
}

static t_bool_num	*get_successor(t_list *list, int value)
{
	int			i;
	int			sum;
	int			pressed;
	t_bool_num	*valid_value;

	valid_value = (t_bool_num *)malloc(sizeof(t_bool_num));
	valid_value->valid = 0;
	valid_value->num = 0;
	if (!list)
		return (valid_value);
	i = 0;
	pressed = INT_MIN;
	while (list)
	{
		sum = value - *(int *)list->content;
		if (sum < 0 && (sum > pressed || i == 0))
		{
			valid_value->valid = 1;
			valid_value->num = *(int *)list->content;
			pressed = sum;
		}
		list = list->next;
		i++;
	}
	return (valid_value);
}

static t_operation	*get_oper(t_operation *op, t_data *data, t_list *aux, int i)
{
	t_bool_num	*value;
	t_operation	*join_op;
	t_operation	*operation_to_do_a;
	t_operation	*operation_to_do_b;

	operation_to_do_b = count_operation_to_b(*(int *)aux->content, data);
	value = get_successor(data->stack_a, *(int *)aux->content);
	if (value->valid)
		operation_to_do_a = count_operation_to_a(value->num, data);
	else
		operation_to_do_a = init_operation();
	free(value);
	join_op = join_operation_to_do(operation_to_do_a, operation_to_do_b);
	if (i == 0 || (join_op && join_op->value < op->value))
	{
		free_operation(op);
		free_all_operation(operation_to_do_a, operation_to_do_b);
		return (join_op);
	}
	else
	{
		free_all_operation(operation_to_do_a, operation_to_do_b);
		free_operation(join_op);
		return (op);
	}
}

t_operation	*get_the_shortest_operation_b_to_a(t_data *data)
{
	int			i;
	int			max;
	t_list		*aux;
	t_operation	*min_op;

	i = 0;
	aux = data->stack_b;
	min_op = init_operation();
	max = stack_max_and_min_value(data->stack_a).max;
	max += stack_max_and_min_value(data->stack_b).max;
	min_op->value = max;
	while (aux)
	{
		min_op = get_oper(min_op, data, aux, i);
		aux = aux->next;
		i++;
	}
	return (min_op);
}
