/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_data *data)
{
	int		fir;
	int		las;
	t_size	size;
	t_list	*aux;

	size = stack_max_and_min_value(data->stack_a);
	aux = data->stack_a;
	fir = *(int *)aux->content;
	while (aux->next)
		aux = aux->next;
	las = *(int *)aux->content;
	if ((size.max == fir && size.min == las)
		|| (size.max == las && size.min != fir))
		sa(data);
	if ((size.min == las && size.max != fir)
		|| (size.max == fir && size.min != las)
		|| (size.min == fir && size.max != las))
		rra(data);
	if (is_in_order(data->stack_a))
		return ;
	else
		case_3(data);
}

void	case_4(t_data *data)
{
	int		fir;
	int		seg;
	int		las;
	t_size	size;
	t_list	*aux;

	size = stack_max_and_min_value(data->stack_a);
	aux = data->stack_a;
	fir = *(int *)aux->content;
	seg = *(int *)aux->next->content;
	while (aux->next)
		aux = aux->next;
	las = *(int *)aux->content;
	if (size.min == fir)
		pb(data);
	if ((size.min == las) || (size.min != fir &&
		size.min != seg && size.min != las))
		rra(data);
	if (size.min == seg)
		sa(data);
	if (ft_lstsize(data->stack_a) == 4)
		case_4(data);
	else
	{
		case_3(data);
		pa(data);
	}
}

void	case_5(t_data *data)
{
	int		fir;
	int		seg;
	int		las;
	t_size	size;
	t_list	*aux;

	size = stack_max_and_min_value(data->stack_a);
	aux = data->stack_a;
	fir = *(int *)aux->content;
	seg = *(int *)aux->next->content;
	while (aux->next)
		aux = aux->next;
	las = *(int *)aux->content;
	if (size.min == fir)
		pb(data);
	if ((size.min == las) || (size.min != fir &&
		size.min != seg && size.min != las))
		rra(data);
	if (size.min == seg)
		sa(data);
	if (ft_lstsize(data->stack_a) == 4)
		case_5(data);
	else
	{
		case_4(data);
		pa(data);
	}
}
