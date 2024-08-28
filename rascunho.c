/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rascunho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_is_number(char *num_in_char)
{
	int	i;

	i = 0;
	while (num_in_char[i])
	{
		if (!ft_isdigit(num_in_char[i]))
		{
			if ((num_in_char[i] == '-' || num_in_char[i] == '+')
				&& (i == 0 || num_in_char[i - 1] == ' ')
				&& ft_isdigit(num_in_char[i + 1]))
				ft_printf("");
			else
				//del
						
		}
		i++;
	}
}

// && ft_isdigit(num_in_char[i + 1] && (i == 0 || num_in_char[i - 1] == ' ')))
int	main(int ac, char **av)
{
	t_list	*list;

	(void)ac;
	check_is_number("111-1");
	return (0);
}

/*
nao esquecer de deletar
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
*/
