
#include "push_swap.h"

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

int	*value_to_pointer(int value)
{
	int *num;

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
