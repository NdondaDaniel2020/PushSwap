/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operating_cost.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*cpy_data(t_data *data)
{
	int		value;
	t_list	*aux;
	t_data	*new_data;

	aux = data->stack_a;
	new_data = (t_data *)malloc(sizeof(t_data));
	init_data(new_data);
	while (aux)
	{
		value = *(int *)aux->content;
		ft_lstadd_back(&new_data->stack_a,
			ft_lstnew((void *)value_to_pointer(value)));
		aux = aux->next;
	}
	aux = data->stack_b;
	while (aux)
	{
		value = *(int *)aux->content;
		ft_lstadd_back(&new_data->stack_b,
			ft_lstnew((void *)value_to_pointer(value)));
		aux = aux->next;
	}
	return (new_data);
}

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

int	get_predecessor(t_list *list, int value)
{
	int	i;
	int	sum;
	int	pos;
	int	pressed;

	(void)value;
	if (!list)
		return (-1);
	i = 0;
	pos = -1;
	pressed = 0;
	while (list)
	{
		sum = value - *(int *)list->content;
		if (sum > 0 && (sum < pressed || i == 0))
		{
			pos = *(int *)list->content;
			pressed = sum;
		}
		list = list->next;
		i++;
	}
	return (pos);
}

void	free_operation(t_operation *op)
{
	free(op->operation_to_do);
	free(op);
}
