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
	long		predecessor;
	t_bool_num	*valid_predecessor;

	valid_predecessor = (t_bool_num *)malloc(sizeof(t_bool_num));
	valid_predecessor->valid = 0;
	valid_predecessor->num = 0;
	if (!list)
		return (valid_predecessor);
	predecessor = LONG_MIN;
	while (list)
	{
		if (*(int *)list->content < value
			&& *(int *)list->content > predecessor)
		{
			valid_predecessor->valid = 1;
			valid_predecessor->num = *(int *)list->content;
			predecessor = *(int *)list->content;
		}
		list = list->next;
	}
	return (valid_predecessor);
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

t_bool_num	*get_successor(t_list *list, int value)
{
	long		successor;
	t_bool_num	*valid_successor;

	valid_successor = (t_bool_num *)malloc(sizeof(t_bool_num));
	valid_successor->valid = 0;
	valid_successor->num = 0;
	if (!list)
		return (valid_successor);
	successor = LONG_MAX;
	while (list)
	{
		if (*(int *)list->content > value
			&& *(int *)list->content < successor)
		{
			valid_successor->valid = 1;
			valid_successor->num = *(int *)list->content;
			successor = *(int *)list->content;
		}
		list = list->next;
	}
	return (valid_successor);
}
