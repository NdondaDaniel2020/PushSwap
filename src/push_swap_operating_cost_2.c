/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operating_cost_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operation	*init_operation(void)
{
	t_operation	*op;

	op = (t_operation *)malloc(sizeof(t_operation));
	if (!op)
		return (NULL);
	op->value = 0;
	op->operation_to_do = NULL;
	return (op);
}

int	opcmp(char *s1, char *s2)
{
	int	len_1;
	int	len_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (len_1 != len_2)
		return (0);
	if (ft_strncmp(s1, s2, len_1 - 1) == 0)
		return (1);
	else
		return (0);
}

char	*ft_charjoin_free(char *s1, char c, int l2)
{
	char	*join;
	int		l1;
	int		i;

	if (!s1 && !c)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < (l1 + l2))
	{
		if (i < l1)
			join[i] = s1[i];
		else
			join[i] = c;
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

void	free_all_operation(t_operation *op_a, t_operation *op_b)
{
	free_operation(op_a);
	free_operation(op_b);
}

void	send_max_to_the_top_of_b(t_data *data) /// revizar onde isoo esta sendo usado
{
	int		pos;
	int		size;
	t_size	max_min;
/// revizar onde isoo esta sendo usado
	size = ft_lstsize(data->stack_b);
	max_min = stack_max_and_min_value(data->stack_b);
	pos = get_pos_in_stack(max_min.max, data->stack_b);
	if (pos > (size / 2))
	{
		pos = size - pos;
		while (pos--)
			rrb(data, 1);
	}
	else if (pos <= (size / 2))
	{
		while (pos--)
			rb(data, 1);
	}
}
