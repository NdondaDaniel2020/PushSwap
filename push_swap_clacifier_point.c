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

static int get_pos_in_stack(int value, t_list *stack)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = stack;
	while (aux->next)
	{
		if (value == *(int *)aux->content)
			return (i);
		aux = aux->next;
		i++;
	}
	return (-1);
}

static char	*join_operation(char *op, char *new_op)
{
	if (!op)
	{
		ft_strlcpy(op, new_op, ft_strlen(new_op));
		return (op);
	}
	else
		return (ft_strjoin_free(op, new_op));
}

static char	*send_to_top(int value, t_data *data, char *operation)
{
	int		fir;
	int		seg;
	int		pos;
	int		size;
	char	*op;
	t_list	*aux;

	op = NULL;
	size = ft_lstsize(data->stack_b);
	aux = data->stack_b;
	fir = *(int *)aux->content;
	seg = *(int *)aux->next->content;
	pos = get_pos_in_stack(value, data->stack_b);
	while (aux->next)
		aux = aux->next;
	if (value == seg)
	{
		sb(data, 0);
		op = join_operation(op, " sb ");
	}
	if (pos > (size / 2))
	{
		rrb(data, 0);
		op = join_operation(op, " rrb ");
	}
	if (value != seg && pos <= (size / 2))
	{
		rb(data, 0);
		op = join_operation(op, " rb ");
	}
	if (value == fir)
		return (op);
	else
		send_to_top(value, data);
}

static t_operation get_the_shortest_operation(t_data *data)
{

	int		value;
	t_list	*aux;

	aux = data->stack_a;
	while (aux)
	{
		value = get_predecessor(data->stack_b, *(int *)aux->content);
		ft_printf("%i\n", *(int *)aux->content);
		aux = aux->next;
	}
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
