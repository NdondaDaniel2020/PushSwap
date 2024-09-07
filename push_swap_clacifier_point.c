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

void	lstls(t_list *list)
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

static	void	case_comand(t_data *data, char *comand)
{
	if (ft_strncmp(comand, "sa", ft_strlen(comand)) == 0)
		sa(data, 1);
	if (ft_strncmp(comand, "sb", ft_strlen(comand)) == 0)
		sb(data, 1);
	if (ft_strncmp(comand, "ss", ft_strlen(comand)) == 0)
		ss(data);
	if (ft_strncmp(comand, "pa", ft_strlen(comand)) == 0)
		pa(data);
	if (ft_strncmp(comand, "pb", ft_strlen(comand)) == 0)
		pb(data);
	if (ft_strncmp(comand, "ra", ft_strlen(comand)) == 0)
		ra(data, 1);
	if (ft_strncmp(comand, "rb", ft_strlen(comand)) == 0)
		rb(data, 1);
	if (ft_strncmp(comand, "rr", ft_strlen(comand)) == 0)
		rr(data);
	if (ft_strncmp(comand, "rra", ft_strlen(comand)) == 0)
		rra(data, 1);
	if (ft_strncmp(comand, "rrb", ft_strlen(comand)) == 0)
		rrb(data, 1);
	if (ft_strncmp(comand, "rrr", ft_strlen(comand)) == 0)
		rrr(data);
}

void	do_operation(t_data *data, char *comand)
{
	int		i;
	char	**split_comand;

	i = 0;
	split_comand = ft_split(comand, ' ');
	while (split_comand[i])
	{
		case_comand(data, split_comand[i]);
		i++;
	}
	free_matrix(split_comand);
}

void	clacifier_point(t_data *data)
{
	int			size;
	t_operation	*op;

	pb(data);
	pb(data);
	size = ft_lstsize(data->stack_a);
	while (size > 4)
	{
		size = ft_lstsize(data->stack_a);
		op = get_the_shortest_operation_a_to_b(data);
		if (op->operation_to_do)
			do_operation(data, op->operation_to_do);
		pb(data);
		free_operation(op);
	}
	case_3(data);
	lstls(data->stack_a);
	lstls(data->stack_b);
}
