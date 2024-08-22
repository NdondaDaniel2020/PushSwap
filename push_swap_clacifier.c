/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clacifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_list	*aux;

	if (ft_lstsize(data->stack_a) > 1)
	{
		aux = data->stack_a;
		data->stack_a = data->stack_a->next;
		aux->next = data->stack_a->next;
		data->stack_a->next = aux;
		ft_printf("sa\n");
	}
}

void	sb(t_data *data)
{
	t_list	*aux;

	if (ft_lstsize(data->stack_b) > 1)
	{
		aux = data->stack_b;
		data->stack_b = data->stack_b->next;
		aux->next = data->stack_b->next;
		data->stack_b->next = aux;
		ft_printf("sb\n");
	}
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
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

void	ra(t_data *data)
{
	t_list	*aux;
	t_list	*fir;

	if (ft_lstsize(data->stack_a) > 1)
	{
		fir = data->stack_a;
		aux = data->stack_a;
		data->stack_a = data->stack_a->next;
		while(aux->next)
			aux = aux->next;
		fir->next = NULL;
		aux->next = fir;
		ft_printf("ra\n");
	}
}

void	rb(t_data *data)
{
	t_list	*aux;
	t_list	*fir;

	if (ft_lstsize(data->stack_b) > 1)
	{
		fir = data->stack_b;
		aux = data->stack_b;
		data->stack_b = data->stack_b->next;
		while(aux->next)
			aux = aux->next;
		fir->next = NULL;
		aux->next = fir;
		ft_printf("rb\n");
	}
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}

void	rra(t_data *data)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(data->stack_a) > 1)
	{
		aux = data->stack_a;
		while(aux->next->next)
			aux = aux->next;
		last = aux->next;
		last->next = data->stack_a;
		aux->next = NULL;
		data->stack_a = last;
		ft_printf("rra\n");
	}
}

void	rrb(t_data *data)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(data->stack_b) > 1)
	{
		aux = data->stack_b;
		while(aux->next->next)
			aux = aux->next;
		last = aux->next;
		last->next = data->stack_b;
		aux->next = NULL;
		data->stack_b = last;
		ft_printf("rrb\n");
	}
}

void	rrr(t_data *data)
{
	ra(data);
	rb(data);
}
