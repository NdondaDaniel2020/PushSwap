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

static int get_position_predecessor(t_list *list, int value)
{
	int	i;
	int	sum;
	int	pos;
	int pressed;

	(void)value;
	if (!list)
		return (-1);
	i = 0;
	pressed = 0;
	while (list)
	{
		sum = value - *(int *)list->content;
		if (sum > 0 && (sum < pressed || i == 0))
		{
			pos = i;
			pressed = sum;
		}
		list = list->next;
		i++;
	}
	return (pos);
}

static t_operation get_the_shortest_operation(t_data *data)
{

	int		pos;
	//t_list	*aux;

	//aux = data->stack_a;
	// cria uma funcao que pegue um numero
	// e retorne a posicao do numero na pilha b
	pos = get_position_predecessor(data->stack_b, 7);
	ft_printf("antecesso de %i esta na pos %i b\n", 7, pos);
	/*
	while (aux)
	{
		pos = get_position_predecessor(data->stack_b, *(int *)aux->content);
		ft_printf("%i %i\n", *(int *)aux->content, pos);
		aux = aux->next;
	}
	*/
	lstls(data->stack_a);
	lstls(data->stack_b);
	return ((t_operation){-1, ""});
}

void	clacifier_point(t_data *data)
{
	t_data	*new_data;

	pb(data);
	pb(data);
	new_data = cpy_data(data);
	get_the_shortest_operation(new_data);
	clean_stack(new_data);
	free(new_data);
}
