/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1 copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:36:37 by obelaizi          #+#    #+#             */
/*   Updated: 2022/12/25 17:37:42 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *head)
{
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
int	get_min(t_stack *head)
{
	int	tmp;

	if (!head)
		return 0;
	tmp = head->data;
	head = head->next;
	while (head)
	{
		if (head->data < tmp)
			tmp = head->data;
		head = head->next;
	}
	return (tmp);
}

int	get_index(t_stack *head, int num)
{
	int	tmp;

	tmp = 1;
	while (head)
	{
		if (head->data == num)
			return (tmp);
		tmp++;
		head = head->next;
	}
	return 0;
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
	int		count;
	int		nm;

	count = 0;
	if (!head || !(head->next))
		return ;
	if (head->data > head->next->data)
		sa(head);
	tmp = get_stack_last(head);
	if (tmp->data < head->data)
		rra(head);
	tmp = head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data && is_sorted(tmp->next))
			break ;
		tmp = tmp->next;
		count++;
	}
	nm = count;
	if (count == ft_lstsize(head) - 1)
		return ;
	while (count--)
		ra(head);
	sa(head);
	while (nm--)
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
}

int	main(int argc, char *argv[])
{
	t_stack	*top_a;
	t_stack	*top_b;
	t_stack	*tmp;
	int		count;
	int		total;
	int		min;
	int		index;

	top_a = NULL;
	top_b = NULL;
	while (--argc)
		add_stack_back(&top_a, ft_stack_new(ft_atoi(*(++argv))));
	total = ft_lstsize(top_a) - 1;
	min = get_min(top_a);
	index = get_index(top_a, min);
	// sort_some_shit_A(top_a);
	// sort_some_shit_A(top_a);
	// sort_some_shit_A(top_a);
	while (1)
	{
		if (is_sorted(top_a))
			break ;
		count = 0;
		tmp = top_a;
		while (1)
		{
			if (top_a->data == min)
			{
				pb(&top_a, &top_b);
				min = get_min(top_a);
				index = get_index(top_a, min);
				break ;
			}
			if (index > argc / 2)
				ra(top_a);
			else
				rra(top_a);
		}
		if (!top_a)
			break ;
	}
	while (top_b)
		pa(&top_a, &top_b);
	// print_lst(top_a);
}
