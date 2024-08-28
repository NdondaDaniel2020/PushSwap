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

int	*value_to_pointer(int value)
{
	int	*num;

	num = (int *)malloc(sizeof(int));
	*num = value;
	return (num);
}

int	main(int ac, char **av)
{
	t_list	*list;

	(void)ac;
	list = NULL;
	ft_lstadd_front(&list, ft_lstnew((void *)value_to_pointer(90)));
	ft_lstadd_front(&list, ft_lstnew((void *)value_to_pointer(80)));
	ft_lstadd_front(&list, ft_lstnew((void *)value_to_pointer(70)));
	ft_lstadd_front(&list, ft_lstnew((void *)value_to_pointer(60)));
	lstls(list);
	return (0);
}

/*nao esquecer de deletar*/
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
