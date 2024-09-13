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

static t_operation	*join_free_oper(t_pos_value a, t_pos_value b, t_data *data)
{
	t_operation	*join;
	t_operation	*operation_to_do_a;
	t_operation	*operation_to_do_b;

	if (a.pos > 0)
		operation_to_do_a = count_operation_to_a(a.value, data);
	else
		operation_to_do_a = init_operation();
	if (b.pos > 0)
		operation_to_do_b = count_operation_to_b(b.value, data);
	else
		operation_to_do_b = init_operation();
	join = join_operation_to_do(operation_to_do_a, operation_to_do_b);
	free_all_operation(operation_to_do_a, operation_to_do_b);
	return (join);
}

static t_pos_value_pair	pos_value_in_stacks_point_a(t_data *data, t_list *aux)
{
	int					size_stack[2];
	t_pos_value_pair	pair;
	t_bool_num			*predecessor;
	t_size				max_min;

	size_stack[0] = ft_lstsize(data->stack_a);
	size_stack[1] = ft_lstsize(data->stack_b);
	pair.a.value = *(int *)aux->content;
	pair.a.pos = get_pos_in_stack(pair.a.value, data->stack_a);
	predecessor = get_predecessor(data->stack_b, pair.a.value);
	pair.b.value = predecessor->num;
	pair.b.pos = get_pos_in_stack(pair.b.value, data->stack_b);
	max_min = stack_max_and_min_value(data->stack_b);
	if (pair.b.pos == -1 || pair.a.value > max_min.max
		|| pair.a.value < max_min.min)
	{
		pair.b.value = max_min.max;
		pair.b.pos = get_pos_in_stack(pair.b.value, data->stack_b);
	}
	if (pair.a.pos > (size_stack[0] / 2))
		pair.a.pos = size_stack[0] - pair.a.pos;
	if (pair.b.pos > (size_stack[1] / 2))
		pair.b.pos = size_stack[1] - pair.b.pos;
	free(predecessor);
	return (pair);
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
		pair = pos_value_in_stacks_point_a(data, aux);
		if (i == 0 || ((pair.a.pos + pair.b.pos)
				< (min_pair.a.pos + min_pair.b.pos)))
		{
			min_pair.a.pos = pair.a.pos;
			min_pair.b.pos = pair.b.pos;
			min_pair.a.value = pair.a.value;
			min_pair.b.value = pair.b.value;
		}
		aux = aux->next;
		i++;
	}
	return (join_free_oper(min_pair.a, min_pair.b, data));
}

static t_pos_value_pair	pos_value_in_stacks_point_b(t_data *data, t_list *aux)
{
	int					size_stack[2];
	t_pos_value_pair	pair;
	t_bool_num			*successor;

	size_stack[0] = ft_lstsize(data->stack_a);
	size_stack[1] = ft_lstsize(data->stack_b);
	pair.b.value = *(int *)aux->content;
	pair.b.pos = get_pos_in_stack(pair.b.value, data->stack_b);
	successor = get_successor(data->stack_a, pair.b.value);
	pair.a.value = successor->num;
	pair.a.pos = get_pos_in_stack(pair.a.value, data->stack_a);
	if (pair.a.pos > (size_stack[0] / 2))
		pair.a.pos = size_stack[0] - pair.a.pos;
	if (pair.b.pos > (size_stack[1] / 2))
		pair.b.pos = size_stack[1] - pair.b.pos;
	free(successor);
	return (pair);
}

t_operation	*get_the_shortest_operation_b_to_a(t_data *data)
{
	int					i;
	t_list				*aux;
	t_pos_value_pair	pair;
	t_pos_value_pair	min_pair;

	i = 0;
	aux = data->stack_b;
	while (aux)
	{
		pair = pos_value_in_stacks_point_b(data, aux);
		if (i == 0 || ((pair.a.pos + pair.b.pos)
				< (min_pair.a.pos + min_pair.b.pos)))
		{
			min_pair.a.pos = pair.a.pos;
			min_pair.b.pos = pair.b.pos;
			min_pair.a.value = pair.a.value;
			min_pair.b.value = pair.b.value;
		}
		aux = aux->next;
		i++;
	}
	return (join_free_oper(min_pair.a, min_pair.b, data));
}
