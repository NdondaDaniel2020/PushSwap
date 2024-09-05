/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clacifier_point.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstls(t_list *list)
{
	int	i;

	i = 0;
	if (list)
	{
		ft_printf("Lista\n");
		while (list)
		{
			ft_printf("%i - %i\n", i, *(int *)list->content);
			list = list->next;
			i++;
		}
		ft_printf("\n");
	}
}

t_operation	*join_operation_to_do(t_operation *op_a, t_operation *op_b)
{
	t_operation	*op;

	op = (t_operation *)malloc(sizeof(t_operation));
	op->value = 0;
	op->operation_to_do = NULL;
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
		op->value = op_b->value;
		op->operation_to_do = join_string_operation_element(
			op_a->operation_to_do, op_b->operation_to_do);
	}
	return (op);
}

t_operation	*count_operation_to_b(int value, t_data *data)
{
	int			pos;
	int			size;
	t_operation	*op;

	op = (t_operation *)malloc(sizeof(t_operation));
	op->value = 0;
	op->operation_to_do = NULL;
	if (value == -1)
		return (op);
	size = ft_lstsize(data->stack_b);
	pos = get_pos_in_stack(value, data->stack_b);
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

t_operation	*count_operation_to_a(int value, t_data *data)
{
	int			pos;
	int			size;
	t_operation	*op;

	op = (t_operation *)malloc(sizeof(t_operation));
	op->value = 0;
	op->operation_to_do = NULL;
	size = ft_lstsize(data->stack_a);
	pos = get_pos_in_stack(value, data->stack_a);
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

void	get_the_shortest_operation(t_data *data)
{
	int			value;
	t_list		*aux;
	t_data		*new_data;
	t_operation	*operation_to_do_a;
	t_operation	*operation_to_do_b;
	t_operation	*join_op;


	aux = data->stack_a;
	while (aux)
	{
		new_data = cpy_data(data);


		
		operation_to_do_a = count_operation_to_a(*(int *)aux->content, new_data);

		value = get_predecessor(new_data->stack_b, *(int *)aux->content);
		operation_to_do_b = count_operation_to_b(value, new_data);

		join_op = join_operation_to_do(operation_to_do_a, operation_to_do_b);
		ft_printf("{{%s}}\n", join_op->operation_to_do);



		free_operation(operation_to_do_a);
		free_operation(operation_to_do_b);
		free_operation(join_op);

		aux = aux->next;
		clean_stack(new_data);
		free(new_data);
	}
}

void	clacifier_point(t_data *data)
{
	pb(data);
	pb(data);

	get_the_shortest_operation(data);
}
