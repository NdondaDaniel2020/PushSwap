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

void		chek_duplicate_in_matrix(char	**spliting_num)
{
	int	i;
    int	c;

	i = 0;
	while (spliting_num[i])
	{
	    c = i + 1;
        while (spliting_num[c])
        {
            if (ft_strlen(spliting_num[c]) == ft_strlen(spliting_num[i])
                && ft_strncmp(spliting_num[i], spliting_num[c], ft_strlen(spliting_num[i])) == 0)
            {
                //free()
            }
            c++;
        }
        i++;
	}
}

int main(int ac, char **av)
{
    char	*spliting_num[5] = {"Danie", "Pedro", "anton", "MArco"};

    ft_printf("[%i]\n", chek_duplicate(spliting_num));

    return (0);
}
