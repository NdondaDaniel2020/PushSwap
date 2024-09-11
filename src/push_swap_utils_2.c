/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_value_in_stack(t_data *data, char *num_in_char)
{
	int	num_in_int;

	check_is_number(data, num_in_char);
	check_size_number(data, num_in_char);
	num_in_int = ft_atoi(num_in_char);
	if (num_in_int == 0 && num_in_int != (num_in_char[0] - '0'))
		error(data);
	else if (num_in_int <= -2147483647 || num_in_int >= 2147483647)
		error(data);
	else
	{
		check_dublicate(data, num_in_int);
		ft_lstadd_back(&data->stack_a,
			ft_lstnew((void *)value_to_pointer(num_in_int)));
	}
}

void	extract_data(t_data *data, char **data_list)
{
	int		i;
	int		c;
	char	**spliting_num;

	i = 1;
	while (data_list[i])
	{
		if (word_counter(data_list[i], ' ') == 0)
			error(data);
		if (word_counter(data_list[i], ' ') == 1)
			add_value_in_stack(data, data_list[i]);
		else
		{
			c = 0;
			spliting_num = ft_split(data_list[i], ' ');
			chek_duplicate_in_matrix(spliting_num, data);
			while (spliting_num[c])
			{
				add_value_in_stack(data, spliting_num[c]);
				c++;
			}
			free_matrix(spliting_num);
		}
		i++;
	}
}

t_size	stack_max_and_min_value(t_list *list)
{
	int		max;
	int		min;

	min = *(int *)list->content;
	max = *(int *)list->content;
	while (list)
	{
		if (*(int *)list->content > max)
			max = *(int *)list->content;
		if (*(int *)list->content < min)
			min = *(int *)list->content;
		list = list->next;
	}
	return ((t_size){min, max});
}

int	is_in_order(t_list *list)
{
	while (list->next)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_in_order_des(t_list *list)
{
	while (list->next)
	{
		if (*(int *)list->content < *(int *)list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
