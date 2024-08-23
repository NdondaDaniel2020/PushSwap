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

void	add_value_in_stack(t_data *data, char *num_in_char)
{
	int	num_in_int;

	num_in_int = ft_atoi(num_in_char);
	if (num_in_int == 0 && num_in_int != (num_in_char[0] - '0'))
	{
		ft_printf("%s not number", num_in_char);
		clean_stack(data);
		exit(1);
	}
	else if (num_in_int < -2147483647 && num_in_int > 2147483647)
	{
		ft_printf("not integer", num_in_char);
		clean_stack(data);
		exit(1);
	}
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
	c = 0;
	while (data_list[i])
	{
		if (word_counter(data_list[i], ' ') == 1)
			add_value_in_stack(data, data_list[i]);
		else
		{
			c = 0;
			spliting_num = ft_split(data_list[i], ' ');
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
