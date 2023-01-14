#include "push_swap.h"
void	print_lst(t_stack *head)
{
	while (head)
	{
		printf("%d|%d| ", head->data, head->index);
		head = head->next;
	}
}
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r') && *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 +(*str - 48);
		str++;
	}
	return (result * sign);
}

int	main(int argc, char *argv[])
{
    t_stack	*top_a;
	t_stack	*top_b;
	int		count;
	int		total;
	int		chunk;
	int		first;
	int		last;

	top_a = NULL;
	top_b = NULL;
	while (--argc)
		add_stack_back(&top_a, ft_stack_new(ft_atoi(*(++argv)), 0));
	total = ft_lstsize(top_a);
	pb(&top_a, &top_b);
	pb(&top_a, &top_b);
	pb(&top_a, &top_b);
	print_lst(top_a);
	printf("\n");
	print_lst(top_b);
	ss(&top_a, &top_b);
	print_lst(top_a);
	printf("\n");
	print_lst(top_b);
}