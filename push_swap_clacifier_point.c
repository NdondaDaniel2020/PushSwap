/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clacifier_point.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*cpy_data(t_data *data)
{
	int		value;
	t_list	*aux;
	t_data	*new_data;

	aux = data->stack_a;
	new_data = (t_data *)malloc(sizeof(t_data));
	init_data(new_data);
	while (aux)
	{
		value = *(int *)aux->content;
		ft_lstadd_back(&new_data->stack_a, 
			ft_lstnew((void *)value_to_pointer(value)));
		aux = aux->next;
	}
	aux = data->stack_b;
	while (aux)
	{
		value = *(int *)aux->content;
		ft_lstadd_back(&new_data->stack_b, 
			ft_lstnew((void *)value_to_pointer(value)));
		aux = aux->next;
	}
	return (new_data);
}

static	void	lstls(t_list *list)
{
	int	i;

	i = 0;
	if (list)
	{
		ft_printf("Lista\n");
		while (list)
		{
			ft_printf("%i - %i\n", i, *(int *)list->content);
			list = list->next;
			i++;
		}
		ft_printf("\n");
	}
}

static t_op get_the_shortest_operation

void	clacifier_point(t_data *data)
{
	t_data	*new_data;

	new_data = cpy_data(data);

	lstls(new_data->stack_a);
	lstls(new_data->stack_b);

	clean_stack(new_data);
	free(new_data);
}
