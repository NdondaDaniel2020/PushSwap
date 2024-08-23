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

static void	lstls(t_list *list)
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

void	case_3(t_data *data)
{
	int		fir;
	int		las;
	t_size	size;
	t_list	*aux;

	size = stack_max_and_min_value(data->stack_a);
	aux = data->stack_a;
	fir = *(int *)aux->content;
	while (aux->next)
		aux = aux->next;
	las = *(int *)aux->content;
	if ((size.max == fir && size.min == las)
		|| (size.max == las && size.min != fir))
		sa(data);
	if ((size.min == las && size.max != fir)
		|| (size.max == fir && size.min != las)
		|| (size.min == fir && size.max != las))
		rra(data);
	if (is_in_order(data->stack_a))
		return ;
	else
		case_3(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	init_data(&data);
	extract_data(&data, av);

	case_3(&data);

	lstls(data.stack_a);
	clean_stack(&data);
	return (0);
}
