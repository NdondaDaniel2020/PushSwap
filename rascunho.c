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

int	opcmp(char *s1, char *s2)
{
	int	len_1;
	int	len_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (len_1 != len_2)
		return (0);
	if (ft_strncmp(s1, s2, len_1 - 1) == 0)
		return (1);
	else
		return (0);
}

char	*ft_charjoin_free(char *s1, char c, int l2)
{
	char	*join;
	int		l1;
	int		i;

	if (!s1 && !c)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < (l1 + l2))
	{
		if (i < l1)
			join[i] = s1[i];
		else
			join[i] = c;
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}




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
		{
			ft_printf("menor[%i] = %s\n", i, menor[i]);
			ft_printf("maior[%i] = %s\n", i, maior[i]);
			join_op = join_with_len(join_op, menor[i][0], ft_strlen(menor[i]));

			ft_printf("join_op = %s\n", join_op);
		}
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



int	main(int ac, char **av)
{
	char	*str;

	(void)ac;

	str = join_string_operation_element(" rra  rra  rra ", " sb ");
	ft_printf("%s\n", str);
	free(str);
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
