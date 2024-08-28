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

static	void	link_case_4_case_3(t_data *data)
{
	if (ft_lstsize(data->stack_a) == 4)
		case_4(data);
	else
	{
		case_3(data);
		pa(data);
	}
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
	if (size.min == las)
		rra(data);
	if (size.min == seg)
		sa(data);
	if (size.min != fir
		&& size.min != seg && size.min != las)
		ra(data);
	link_case_4_case_3(data);
}

static	void	link_case_5_case_4(t_data *data, t_size size)
{
	if (ft_lstsize(data->stack_a) == 5)
		case_5(data, size);
	else
	{
		case_4(data);
		pa(data);
	}
}

void	case_5(t_data *data, t_size size)
{
	int		point[4];
	t_list	*aux;

	aux = data->stack_a;
	point[0] = *(int *)aux->content;
	point[1] = *(int *)aux->next->content;
	while (aux->next)
	{
		if (!aux->next->next)
			point[2] = *(int *)aux->content;
		aux = aux->next;
	}
	point[3] = *(int *)aux->content;
	if (size.min == point[0])
		pb(data);
	if ((size.min == point[3]) || (size.min == point[2]))
		rra(data);
	if (size.min == point[1])
		sa(data);
	if (size.min != point[0] && size.min != point[2]
		&& size.min != point[1] && size.min != point[3])
		ra(data);
	link_case_5_case_4(data, size);
}
