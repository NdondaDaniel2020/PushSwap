/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operating_cost_1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos_in_stack(int value, t_list *stack)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = stack;
	while (aux)
	{
		if (value == *(int *)aux->content)
			return (i);
		aux = aux->next;
		i++;
	}
	return (-1);
}

t_bool_num	*get_predecessor(t_list *list, int value)
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
	pressed = stack_max_and_min_value(list).max;
	while (list)
	{
		sum = value - *(int *)list->content;
		if (sum > 0 && (sum < pressed || i == 0))
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

void	free_operation(t_operation *op)
{
	if (op->operation_to_do)
		free(op->operation_to_do);
	free(op);
}

t_operation	*join_each_element(t_operation *op, char *new_op)
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
