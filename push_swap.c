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

void	case_3(t_data *data)
{
	int		max;
	int		min;
	// int	fir;
	// int	las;
	t_list	*aux;


	aux = data->stack_a;
	min = *(int *)aux->content;
	max = *(int *)aux->content;
	while (aux)
	{
		if (*(int *)aux->content > max)
			max = *(int *)aux->content;
		if (*(int *)aux->content < min)
			min = *(int *)aux->content;
		aux = aux->next;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	init_data(&data);
	extract_data(&data, av);

	lstls(data.stack_a);

	clean_stack(&data);
	return (0);
}
