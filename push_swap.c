/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
}

static void	resolution(t_data *data)
{
	int		i;
	t_size	size;

	size = stack_max_and_min_value(data->stack_a);
	if (!is_in_order(data->stack_a))
	{
		i = ft_lstsize(data->stack_a);
		if (i >= 2 && i <= 3)
			case_3(data);
		if (i == 4)
			case_4(data);
		if (i == 5)
			case_5(data, size);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	init_data(&data);
	extract_data(&data, av);
	resolution(&data);
	clean_stack(&data);
	return (0);
}
