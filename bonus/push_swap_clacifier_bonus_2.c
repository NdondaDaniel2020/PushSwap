/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clacifier_bonus_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, int i)
{
	t_list	*aux;
	t_list	*fir;

	if (ft_lstsize(data->stack_a) > 1)
	{
		fir = data->stack_a;
		aux = data->stack_a;
		data->stack_a = data->stack_a->next;
		while (aux->next)
			aux = aux->next;
		fir->next = NULL;
		aux->next = fir;
		if (i == 1)
			write(1, "ra\n", 3);
	}
}

void	rb(t_data *data, int i)
{
	t_list	*aux;
	t_list	*fir;

	if (ft_lstsize(data->stack_b) > 1)
	{
		fir = data->stack_b;
		aux = data->stack_b;
		data->stack_b = data->stack_b->next;
		while (aux->next)
			aux = aux->next;
		fir->next = NULL;
		aux->next = fir;
		if (i == 1)
			write(1, "rb\n", 3);
	}
}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	write(1, "rr\n", 3);
}
