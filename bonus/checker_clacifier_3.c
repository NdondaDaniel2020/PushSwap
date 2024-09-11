/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_clacifier_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_data *data, int i)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(data->stack_a) > 1)
	{
		aux = data->stack_a;
		while (aux->next->next)
			aux = aux->next;
		last = aux->next;
		last->next = data->stack_a;
		aux->next = NULL;
		data->stack_a = last;
		if (i == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_data *data, int i)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(data->stack_b) > 1)
	{
		aux = data->stack_b;
		while (aux->next->next)
			aux = aux->next;
		last = aux->next;
		last->next = data->stack_b;
		aux->next = NULL;
		data->stack_b = last;
		if (i == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	write(1, "rrr\n", 4);
}
