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

static void	free_all_operation(t_operation *op_a, t_operation *op_b)
{
	free_operation(op_a);
	free_operation(op_b);
}

static t_operation	*min_oper(t_operation *op, t_data *data, t_list *aux, int i)
{
	int			value;
	t_operation	*join_op;
	t_operation	*operation_to_do_a;
	t_operation	*operation_to_do_b;

	operation_to_do_a = count_operation_to_a(*(int *)aux->content, data);
	value = get_predecessor(data->stack_b, *(int *)aux->content);
	if (value != *(int *)aux->content)
		operation_to_do_b = count_operation_to_b(value, data);
	else
		operation_to_do_b = init_operation();
	join_op = join_operation_to_do(operation_to_do_a, operation_to_do_b);
	if (i == 0 || (join_op && join_op->value < op->value))
	{
		op = join_op;
		free_all_operation(operation_to_do_a, operation_to_do_b);
		return (op);
	}
	else
	{
		free_all_operation(operation_to_do_a, operation_to_do_b);
		free_operation(join_op);
		return (op);
	}
}

t_operation	*get_the_shortest_operation(t_data *data)
{
	int			i;
	t_list		*aux;
	t_data		*new_data;
	t_operation	*min_op;

	i = 0;
	aux = data->stack_a;
	while (aux)
	{
		new_data = cpy_data(data);
		min_op = min_oper(min_op, new_data, aux, i);
		aux = aux->next;
		clean_stack(new_data);
		free(new_data);
		i++;
	}
	return (min_op);
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
	// int			size;
	t_operation	*op;

	pb(data);
	pb(data);

	ft_printf("\n//////////////////////////////////////////\n");
	lstls(data->stack_a);
	lstls(data->stack_b);
	
	op = get_the_shortest_operation(data);
	ft_printf("{{%s} %i }\n", op->operation_to_do, op->value);
	if (op->operation_to_do)
		do_operation(data, op->operation_to_do);
	pb(data);

	ft_printf("\n//////////////////////////////////////////\n");
	lstls(data->stack_a);
	lstls(data->stack_b);

	op = get_the_shortest_operation(data);
	ft_printf("{{%s} %i }\n", op->operation_to_do, op->value);
	if (op->operation_to_do)
		do_operation(data, op->operation_to_do);
	pb(data);

	ft_printf("\n//////////////////////////////////////////\n");
	lstls(data->stack_a);
	lstls(data->stack_b);

	op = get_the_shortest_operation(data);
	ft_printf("{{%s} %i }\n", op->operation_to_do, op->value);
	if (op->operation_to_do)
		do_operation(data, op->operation_to_do);
	pb(data);

	ft_printf("\n//////////////////////////////////////////\n");
	lstls(data->stack_a);
	lstls(data->stack_b);

	op = get_the_shortest_operation(data);
	ft_printf("{{%s} %i }\n", op->operation_to_do, op->value);
	if (op->operation_to_do)
		do_operation(data, op->operation_to_do);
	pb(data);
	
	ft_printf("\n//////////////////////////////////////////\n");
	ft_printf("\n depois do pb verifica se a pilha ba esta orde nada de forma descrescente se nao aplicar rb\n");
	ft_printf("\n//////////////////////////////////////////\n");
	
	// size = ft_lstsize(data->stack_a);
	// while (size > 3)
	// {
	// 	size = ft_lstsize(data->stack_a);

	// 	op = get_the_shortest_operation(data);
	// 	ft_printf("{{%s} %i }\n", op->operation_to_do, op->value);
	// 	do_operation(data, op->operation_to_do);
	// 	pb(data);
	// }
	free_operation(op);
}
