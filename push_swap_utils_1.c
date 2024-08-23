/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstdel_front(t_list **list)
{
	t_list	*removed;

	if (*list)
	{
		removed = *list;
		*list = removed->next;
		free(removed->content);
		free(removed);
		removed = NULL;
	}
}

void	clean_stack(t_data *data)
{
	while (data->stack_a != NULL)
		lstdel_front(&data->stack_a);
	while (data->stack_b != NULL)
		lstdel_front(&data->stack_b);
}

int	*value_to_pointer(int value)
{
	int	*num;

	num = (int *)malloc(sizeof(int));
	*num = value;
	return (num);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	check_dublicate(t_data *data, int num)
{
	t_list	*aux;

	aux = data->stack_a;
	while (aux)
	{
		if (*(int *)aux->content == num)
		{
			ft_printf("value duplicate");
			clean_stack(data);
			exit(1);
		}
		aux = aux->next;
	}
}
