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

int	*value_to_pointer_(int value)
{
	int	*num;

	num = (int *)malloc(sizeof(int));
	*num = value;
	return (num);
}

t_bool_num	*get_successor_(t_list *list, int value)
{
	long		successor;
	t_bool_num	*valid_successor;

	valid_successor = (t_bool_num *)malloc(sizeof(t_bool_num));
	valid_successor->valid = 0;
	valid_successor->num = 0;
	if (!list)
		return (valid_successor);
	successor = LONG_MAX;
	while (list)
	{
        if (*(int *)list->content > value
            && *(int *)list->content < successor)
        {
            valid_successor->valid = 1;
            valid_successor->num = *(int *)list->content;
            successor = *(int *)list->content;
        }
		list = list->next;
	}
	return (valid_successor);
}

t_bool_num	*get_predecessor(t_list *list, int value)
{
	long		predecessor;
	t_bool_num	*valid_predecessor;

	valid_predecessor = (t_bool_num *)malloc(sizeof(t_bool_num));
	valid_predecessor->valid = 0;
	valid_predecessor->num = 0;
	if (!list)
		return (valid_predecessor);
	predecessor = LONG_MIN;
	while (list)
	{
		if (*(int *)list->content < value && *(int *)list->content > predecessor)
        {
            valid_predecessor->valid = 1;
            valid_predecessor->num = *(int *)list->content;
            predecessor = *(int *)list->content;
        }
		list = list->next;
	}
	return (valid_predecessor);
}

int main(int ac, char **av)
{
    
    t_list *list;
    t_list *aux;
    t_bool_num  *successor;
    t_bool_num  *predecessor;

    list = NULL;
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(-1)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(6)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(1)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(-3)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(-2)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(-5)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(2)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(3)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(-4)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(5)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(-6)));
    ft_lstadd_back(&list, ft_lstnew((void *)value_to_pointer_(4)));
      
    aux = list;
    while (aux)
    {
        successor = get_successor_(list, *(int *)aux->content);
        predecessor = get_predecessor_(list, *(int *)aux->content);
        ft_printf("[%i] = [%i]",predecessor->valid,predecessor->num);
        ft_printf(" <- %i -> ", *(int *)aux->content);
        ft_printf("[%i] = [%i]\n\n", successor->num, successor->valid);
        aux =  aux->next;
    }
    return (0);
}
