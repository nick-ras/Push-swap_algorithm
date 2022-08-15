#include "../push_swap.h"

t_push	*ft_lstlast_new(t_push *lst)
{

	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_atoi_push(char *str, t_push *stack_a)
{
	int			sign;
	int			i;
	long int	number;

	i = 0;
	sign = 1;
	while (str[i] == 32 || ((str[i] >= 9) && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
				sign = -1;
		i++;
	}
	number = 0;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		if (number > 2147483648 && sign == -1)
			exit_statement_and_free(stack_a, 1);
		if (number > 2147483647 && sign == 1)
			exit_statement_and_free(stack_a, 1);
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (sign * number);
}