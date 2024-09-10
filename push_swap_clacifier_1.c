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
			ft_printf("sa\n");
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
			ft_printf("sb\n");
	}
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	ft_printf("ss\n");
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
		ft_printf("pa\n");
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
		ft_printf("pb\n");
	}
}
