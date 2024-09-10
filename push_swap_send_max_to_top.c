/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_send_max_to_top.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operation	*send_max_to_the_top_of_b(t_data *data)
{
	int			pos;
	int			size;
	t_size		max_min;
	t_operation	*op;

	op = init_operation();
	size = ft_lstsize(data->stack_b);
	max_min = stack_max_and_min_value(data->stack_b);
	while (!is_in_order_des(data->stack_b))
	{
		pos = get_pos_in_stack(max_min.max, data->stack_b);
		if (pos > (size / 2) - 1)
		{
			rrb(data, 0);
			op = join_each_element(op, " rrb ");
		}
		if (pos <= (size / 2) - 1)
		{
			rb(data, 0);
			op = join_each_element(op, " rb ");
		}
	}
	return (op);
}
