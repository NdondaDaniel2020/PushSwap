/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_data *data)
{
	write(2, "Error\n", 6);
	clean_stack(data);
	exit(1);
}

static char	*fun_number_max(void)
{
	return ("2147483647");
}

void	check_size_number(t_data *data, char *num_in_char)
{
	int		i;
	int		ix;
	char	*number_max;

	i = 0;
	ix = 0;
	number_max = fun_number_max();
	if ((ft_strlen(num_in_char) == 10)
		|| (ft_strlen(num_in_char) == 11 && num_in_char[0] == '-'))
	{
		if (ft_strlen(num_in_char) == 11 && num_in_char[0] == '-')
			i++;
		while (num_in_char[i])
		{
			if (num_in_char[i] > number_max[ix])
				error(data);
			i++;
			ix++;
		}
	}
	else if (ft_strlen(num_in_char) > 10)
		error(data);
}

void	check_is_number(t_data *data, char *num_in_char)
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
