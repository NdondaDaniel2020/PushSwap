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

t_operation	*join_operation(t_operation *op, char *new_op)
{
	if (!op->operation_to_do)
	{
		op->operation_to_do = (char *)malloc(ft_strlen(new_op) + 1);
		if (!op->operation_to_do)
			return (op);
		op->value++;
		ft_strlcpy(op->operation_to_do, new_op, ft_strlen(new_op) + 1);
		return (op);
	}
	else
	{
		op->operation_to_do = ft_strjoin_free(op->operation_to_do, new_op);
		if (!op->operation_to_do)
			return (op);
		op->value++;
		return (op);
	}
}

t_operation	*join_operation_to_do(t_operation *op_a, t_operation *op_b)
{
	int		i;
	char	**to_do_a;
	char	**to_do_b;

	i = 0;
	to_do_a = ft_split(op_a->operation_to_do, ' ');
	to_do_b = ft_split(op_b->operation_to_do, ' ');
	ft_printf("%s %s\n", to_do_a[i], to_do_b[i]);
	// while (to_do_a[i] || to_do_b[i])
	// {
	// 	ft_printf("{%s} {%s}", to_do_a[i], to_do_b[i]);
	// 	i++;
	// }
	// op_b->operation_to_do;
	// free_operation(operation_to_do_a);
	return (op_a);
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
			op = join_operation(op, " sb ");
		}
		else if (pos > (size / 2))
		{
			rrb(data, 0);
			op = join_operation(op, " rrb ");
		}
		else if (value != *(int *)data->stack_b->content
			&& value != *(int *)data->stack_b->next->content
			&& pos <= (size / 2))
		{
			rb(data, 0);
			op = join_operation(op, " rb ");
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
			op = join_operation(op, " sa ");
		}
		else if (pos > (size / 2))
		{
			rra(data, 0);
			op = join_operation(op, " rra ");
		}
		else if (value != *(int *)data->stack_a->content
			&& value != *(int *)data->stack_a->next->content
			&& pos <= (size / 2))
		{
			ra(data, 0);
			op = join_operation(op, " ra ");
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


	aux = data->stack_a;
	while (aux)
	{
		new_data = cpy_data(data);

	
		
		operation_to_do_a = count_operation_to_a(*(int *)aux->content, new_data);

		value = get_predecessor(new_data->stack_b, *(int *)aux->content);
		operation_to_do_b = count_operation_to_b(value, new_data);


		join_operation_to_do(operation_to_do_a, operation_to_do_b);

		free_operation(operation_to_do_a);
		free_operation(operation_to_do_b);


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
