/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_join_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_with_len(char *join_op, char ch, int len)
{
	join_op = ft_strjoin_free(join_op, " ");
	join_op = ft_charjoin_free(join_op, ch, len);
	return (join_op);
}

static char	*join_two_operations(char *join_op, char *menor, char *maior)
{
	join_op = ft_strjoin_free(join_op, " ");
	join_op = ft_strjoin_free(join_op, menor);
	join_op = ft_strjoin_free(join_op, " ");
	join_op = ft_strjoin_free(join_op, maior);
	return (join_op);
}

static char	*join_string_operation(char *join_op, char **menor, char **maior)
{
	int		i;

	i = 0;
	while (menor[i])
	{
		if (opcmp(menor[i], maior[i]) && maior[i][0] != 'p')
			join_op = join_with_len(join_op, menor[i][0], ft_strlen(menor[i]));
		else
			join_op = join_two_operations(join_op, menor[i], maior[i]);
		i++;
	}
	while (maior[i])
	{
		join_op = ft_strjoin_free(join_op, " ");
		join_op = ft_strjoin_free(join_op, maior[i]);
		i++;
	}
	free_matrix(menor);
	free_matrix(maior);
	return (join_op);
}

char	*join_string_operation_element(char *s_a, char *s_b)
{
	int		count_word_a;
	int		count_word_b;
	char	**menor;
	char	**maior;
	char	*join_op;

	join_op = (char *)malloc(sizeof(char));
	join_op[0] = '\0';
	count_word_a = word_counter(s_a, ' ');
	count_word_b = word_counter(s_b, ' ');
	if (count_word_b < count_word_a)
	{
		menor = ft_split(s_b, ' ');
		maior = ft_split(s_a, ' ');
	}
	else
	{
		menor = ft_split(s_a, ' ');
		maior = ft_split(s_b, ' ');
	}
	join_op = join_string_operation(join_op, menor, maior);
	return (join_op);
}
