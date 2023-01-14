/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:36:37 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/10 21:59:40 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int get_max(t_stack *head)
// {
// 	int	tmp;
	
// 	tmp = head->data;
// 	while (head)
// 	{
// 		if (head->data > tmp)
// 			tmp = head->data;
// 		head = head->next;
// 	}
// 	return (tmp);
// }

int	check_big(t_stack *head, int data)
{
	while (head)
	{
		if (head->data > data)
			return (0);
		head = head->next;
	}
	return (1);
}

int check_small(t_stack *head, int data)
{
	while (head)
	{
		if (head->data < data)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_last(t_stack *head, int chunk)
{
	while (head)
	{
		if (head->index < chunk)
			return (1);
		head = head->next;
	}
	return (0);
}

int	scan_last(t_stack *head, int chunk)
{
	int	count;
	
	count = 0;
	while(is_last(head, chunk))
	{
		head = head->next;
		count++;
	}
	return (count);
}

int	scan_first(t_stack *head, int chunk)
{
	int	count;
	
	count = 1;
	while(head)
	{
		if (head->index < chunk)
			return (count);
		head = head->next;
		count++;
	}
	return (count);
}

int	get_pos(t_stack *head, int index)
{
	int	count;

	count = 0;
	while (head)
	{
		if (head->index == index)
			return (count);
		head = head->next;
		count++;
	}
	return (0);
}

int	get_min(t_stack *head, int check)
{
	int		tmp;
	t_stack	*nd;

	nd = head;
	tmp = head->data;
	while (head && tmp <= check)
	{
		tmp = head->data; 
		head = head->next;
	}
	while (head)
	{
		if (head->data <= check)
		{
			head = head->next;
			continue ;
		}
		if (head->data < tmp)
			tmp = head->data;
		head = head->next;
	}
	return (tmp);
}

int	is_sorted(t_stack *head)
{
	if (!head)
		return (0);
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	set_index(t_stack *head, int size_lst)
{
	int		tmp;
	int		min;
	t_stack	*tmp_head;

	tmp = 0;
	min = -2147483648;
	tmp_head = head;
	while (tmp < size_lst)
	{
		head = tmp_head;
		min = get_min(tmp_head, min);
		while (head)
		{
			if (head->data == min)
			{
				head->index = tmp++;
				break ;
			}
			head = head->next;
		}
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

void	print_lst(t_stack *head)
{
	while (head)
	{
		printf("%d|%d| ", head->data, head->index);
		head = head->next;
	}
}

void	sort_3(t_stack **a, int start_index)
{
	if (is_sorted((*a)->next))
	{
		if ((*a)->data > (*a)->next->next->data)
			ra(a);
		else
			sa(a);
	}
	else if ((*a)->index == start_index + 2 && (*a)->next->index == start_index + 1 && (*a)->next->next->index == start_index)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->index == start_index && (*a)->next->index == start_index + 2 && (*a)->next->next->index == start_index + 1)
	{
		sa(a);
		ra(a);
	}
	else
		rra(a);
}

void	sort_4(t_stack **a, t_stack **b, int start_index)
{
	int	pos;

	while ((*a)->index != start_index)
	{
		pos = get_pos(*a, 0);
		if (pos <= 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_3(a, start_index + 1);
	pa(a, b);
}

void	sort_ez(t_stack **a, t_stack **b)
{
	int pos;

	if (is_sorted(*a))
		return ;
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a, 0);
	else if (ft_lstsize(*a) == 4)
		sort_4(a, b, 0);
	else
	{
		while ((*a)->index != 0)
		{
			pos = get_pos(*a, 0);
			if (pos <= 3)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		sort_4(a, b, 1);
		pa(a, b);
	}
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
	set_index(top_a, ft_lstsize(top_a));
	total = ft_lstsize(top_a);
	if (total <= 5)
	{
		sort_ez(&top_a, &top_b);
		return (0);
	}
	else if (total < 20)
		chunk = total;
	else if (total <= 200)
		chunk = total / 5;
	else if (total == 500)
		chunk = total / 10;
	 else
		chunk = total / 15;
	count = chunk;
	while (top_a )
	{
		if (!top_a)
			break ;
		if (ft_lstsize(top_b) == count)
			count = count + chunk;
		while (top_a->index >= count)
		{
			first = scan_first(top_a, count) - 1;
			last = scan_last(top_a, count) - 1;
			if (ft_lstsize(top_a) - last > first)
				ra(&top_a);
			else
				rra(&top_a);
		}
		if (top_a->index >= count - (chunk / 2))
			pb(&top_a, &top_b);
		else
		{
			pb(&top_a, &top_b);
			if (top_a && top_a->index >= count)
			{
				first = scan_first(top_a, count) - 1;
				last = scan_last(top_a, count) - 1;
				if (ft_lstsize(top_a) - last > first)
					rr(&top_a, &top_b);
				else
				{
					rra(&top_a);
					rb(&top_b);
				}
			}
			else
				rb(&top_b);
		}
	}
	count = total - 1;
	while (top_b)
	{
		if (top_b->index == count)
		{
			pa(&top_a, &top_b);
			count--;
		}
		else
		{
			if (get_pos(top_b, count) > (chunk / 2) - 1)
				rrb(&top_b);
			else
				rb(&top_b);
		}
	}

//  print_lst(top_a);
}
