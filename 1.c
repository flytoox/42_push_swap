/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:36:37 by obelaizi          #+#    #+#             */
/*   Updated: 2022/12/20 23:41:16 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_lst(t_stack *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

void	sort_some_shit_A(t_stack *head)
{
	t_stack	*tmp;

	if (!head || !(head->next))
		return ;
	if (head->data > head->next->data)
		sa(head);
	tmp = get_stack_last(head);
	if (tmp->data < head->data)
		rra(head);
}

void	sort_some_shit_B(t_stack *head)
{
	t_stack	*tmp;
	int		count;
	int		nm;

	count = 0;
	if (!head || !(head->next))
		return ;
	tmp = get_stack_last(head);
	if (tmp->data > head->data)
		rb(head);
	if (head->data < head->next->data)
		sb(head);
	tmp = head;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			break ;
		count++;
		tmp = tmp->next;
	}
	nm = count;
	if (count == ft_lstsize(head) - 1)
		return ;
	while (count--)
		rb(head);
	sb(head);
	while (nm--)
		rrb(head);
	// tmp = head;
	// while (tmp->next)
	// {
	// 	if (tmp->data < tmp->next->data || tmp->data < head->data)
	// 		break ;
	// 	tmp = tmp->next;
	// }
	
	// printf("f\n");
	// if (tmp->next)
	// 	sort_some_shit_B(head);
}

int	main(int argc, char *argv[])
{
	t_stack	*top_a;
	t_stack	*top_b;
	t_stack	*tmp;
	int		count;
	int		total;

	top_a = NULL;
	top_b = NULL;
	while (--argc)
		add_stack_back(&top_a, ft_stack_new(ft_atoi(*(++argv))));
	total = ft_lstsize(top_a) - 1;
	while (1)
	{
		count = 0;
		sort_some_shit_A(top_a);
		tmp = top_a;
		/*while (tmp->next)
		{
			if (tmp->data > tmp->next->data)
				break ;
			count++;
			tmp = tmp->next;
		}*/
		if (!total)
			break ;
		pb(&top_a, &top_b);
		total--;
		sort_some_shit_A(top_a);
		sort_some_shit_B(top_b);
	}
	while (top_b)
		pa(&top_a, &top_b);
	//print_lst(top_a);
}
