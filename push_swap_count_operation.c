/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count_operation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operation	*join_operation_to_do(t_operation *op_a, t_operation *op_b)
{
	t_operation	*op;
	char		*join_op;

	op = init_operation();
	if (!op_a && !op_b)
		return (NULL);
	if (op_a->operation_to_do && !op_b->operation_to_do)
	{
		op->value = op_a->value;
		op->operation_to_do = ft_strdup(op_a->operation_to_do);
	}
	else if (op_b->operation_to_do && !op_a->operation_to_do)
	{
		op->value = op_b->value;
		op->operation_to_do = ft_strdup(op_b->operation_to_do);
	}
	else if (op_a->operation_to_do && op_b->operation_to_do)
	{
		join_op = join_string_operation_element(
				op_a->operation_to_do, op_b->operation_to_do);
		op->value = word_counter(join_op, ' ');
		op->operation_to_do = join_op;
	}
	return (op);
}

static t_operation	*operation_to_b(int value, t_data *data, int pos, int size)
{
	t_operation	*op;

	op = init_operation();
	while (value != *(int *)data->stack_b->content)
	{
		if (value == *(int *)data->stack_b->next->content)
		{
			sb(data, 0);
			op = join_each_element(op, " sb ");
		}
		else if (pos > (size / 2))
		{
			rrb(data, 0);
			op = join_each_element(op, " rrb ");
		}
		else if (value != *(int *)data->stack_b->content
			&& value != *(int *)data->stack_b->next->content
			&& pos <= (size / 2))
		{
			rb(data, 0);
			op = join_each_element(op, " rb ");
		}
	}
	return (op);
}

t_operation	*count_operation_to_b(int value, t_data *data)
{
	int			pos;
	int			size;
	t_operation	*op;

	size = ft_lstsize(data->stack_b);
	pos = get_pos_in_stack(value, data->stack_b);
	op = operation_to_b(value, data, pos, size);
	return (op);
}

static t_operation	*operation_to_a(int value, t_data *data, int pos, int size)
{
	t_operation	*op;

	op = init_operation();
	while (value != *(int *)data->stack_a->content)
	{
		if (value == *(int *)data->stack_a->next->content)
		{
			sa(data, 0);
			op = join_each_element(op, " sa ");
		}
		else if (pos > (size / 2))
		{
			rra(data, 0);
			op = join_each_element(op, " rra ");
		}
		else if (value != *(int *)data->stack_a->content
			&& value != *(int *)data->stack_a->next->content
			&& pos <= (size / 2))
		{
			ra(data, 0);
			op = join_each_element(op, " ra ");
		}
	}
	return (op);
}

t_operation	*count_operation_to_a(int value, t_data *data)
{
	int			pos;
	int			size;
	t_operation	*op;

	size = ft_lstsize(data->stack_a);
	pos = get_pos_in_stack(value, data->stack_a);
	op = operation_to_a(value, data, pos, size);
	return (op);
}
