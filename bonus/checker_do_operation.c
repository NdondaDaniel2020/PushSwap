/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_do_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	valid_command(char *command)
{
	if (ft_strncmp(command, "sa", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "sb", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "ss", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "pa", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "pb", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "ra", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "rb", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "rr", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "rra", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "rrb", ft_strlen(command) - 1) == 0)
		return (1);
	else if (ft_strncmp(command, "rrr", ft_strlen(command) - 1) == 0)
		return (1);
	return (0);
}

static	void	case_command(t_data *data, char *command)
{
	if (ft_strncmp(command, "sa", ft_strlen(command) - 1) == 0)
		sa(data, 1);
	else if (ft_strncmp(command, "sb", ft_strlen(command) - 1) == 0)
		sb(data, 1);
	else if (ft_strncmp(command, "ss", ft_strlen(command) - 1) == 0)
		ss(data);
	else if (ft_strncmp(command, "pa", ft_strlen(command) - 1) == 0)
		pa(data);
	else if (ft_strncmp(command, "pb", ft_strlen(command) - 1) == 0)
		pb(data);
	else if (ft_strncmp(command, "ra", ft_strlen(command) - 1) == 0)
		ra(data, 1);
	else if (ft_strncmp(command, "rb", ft_strlen(command) - 1) == 0)
		rb(data, 1);
	else if (ft_strncmp(command, "rr", ft_strlen(command) - 1) == 0)
		rr(data);
	else if (ft_strncmp(command, "rra", ft_strlen(command) - 1) == 0)
		rra(data, 1);
	else if (ft_strncmp(command, "rrb", ft_strlen(command) - 1) == 0)
		rrb(data, 1);
	else if (ft_strncmp(command, "rrr", ft_strlen(command) - 1) == 0)
		rrr(data);
}

void	do_operation(t_data *data, char *command)
{
	int		i;
	char	**split_command;

	i = 0;
	split_command = ft_split(command, ' ');
	while (split_command[i])
	{
		case_command(data, split_command[i]);
		i++;
	}
	free_matrix(split_command);
}
