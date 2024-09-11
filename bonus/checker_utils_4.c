/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_number(char *num_in_char)
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
				write(1, "", 0);
			else
				return (0);
		}
		i++;
	}
    return (1);
}

static void check_is_number_in_matrix(char **spliting_num, t_data *data)
{
	int	i;

	i = 0;
	while (spliting_num[i])
	{
		if (is_number(spliting_num[i]) == 0)
		{
			free_matrix(spliting_num);
			error(data);
		}
		i++;
	}
}

void	chek_duplicate_in_matrix(char **spliting_num, t_data *data)
{
	int	i;
    int	c;

	i = 0;
	check_is_number_in_matrix(spliting_num, data);
	while (spliting_num[i])
	{
	    c = i + 1;
        while (spliting_num[c])
        {
            if (ft_strlen(spliting_num[c]) == ft_strlen(spliting_num[i])
                && ft_strncmp(spliting_num[i], spliting_num[c], 
					ft_strlen(spliting_num[i])) == 0)
            {
                free_matrix(spliting_num);
				error(data);
            }
            c++;
        }
        i++;
	}
}
