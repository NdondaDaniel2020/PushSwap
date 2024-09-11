/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
}

void	resolution(t_data *data)
{
	char	*command;

	command = get_next_line(0);
	while (command != NULL)
	{
		if (valid_command(command))
			do_operation(data, command);
		else
		{
			free(command);
			error(data);
		}
		free(command);
		command = get_next_line(0);
	}
	if (is_in_order(data->stack_a))
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	if (ac > 1)
	{
		init_data(&data);
		extract_data(&data, av);
		resolution(&data);
		lstls(data.stack_a);
		clean_stack(&data);
	}
	return (0);
}
