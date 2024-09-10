/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clacifier_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int i)
{
	t_list	*aux;

	if (ft_lstsize(data->stack_a) > 1)
	{
		aux = data->stack_a;
		data->stack_a = data->stack_a->next;
		aux->next = data->stack_a->next;
		data->stack_a->next = aux;
		if (i == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_data *data, int i)
{
	t_list	*aux;

	if (ft_lstsize(data->stack_b) > 1)
	{
		aux = data->stack_b;
		data->stack_b = data->stack_b->next;
		aux->next = data->stack_b->next;
		data->stack_b->next = aux;
		if (i == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	write(1, "ss\n", 3);
}

void	pa(t_data *data)
{
	t_list	*aux;

	if (ft_lstsize(data->stack_b) > 0)
	{
		aux = data->stack_b;
		data->stack_b = data->stack_b->next;
		aux->next = data->stack_a;
		data->stack_a = aux;
		write(1, "pa\n", 3);
	}
}

void	pb(t_data *data)
{
	t_list	*aux;

	if (ft_lstsize(data->stack_a) > 0)
	{
		aux = data->stack_a;
		data->stack_a = data->stack_a->next;
		aux->next = data->stack_b;
		data->stack_b = aux;
		write(1, "pb\n", 3);
	}
}
