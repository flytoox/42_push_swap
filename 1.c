/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:36:37 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/08 12:33:40 by obelaizi         ###   ########.fr       */
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
	if (total <= 200)
		chunk = total / 5;
	else if (total == 500)
		chunk = total / 12;
	// else if (total <= 5)
	// 	sort_ez(top_a);
	count = chunk;
	// print_lst(top_a);
	// printf("(%d) (%d)", scan_first(top_a, count), scan_last(top_a, count));
	// print_lst(top_a);
	while (top_a)
	{
		// if (ft_lstsize(top_a) <= chunk)
		// 	break ;
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
		if (count > chunk)
		{
		if (top_a->index < count - (chunk / 2))
			pb(&top_a, &top_b);
		else
		{
			pb(&top_a, &top_b);
			
			rb(&top_b);
		}
		}
		else
			pb(&top_a, &top_b);

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
			if (get_pos(top_b, count) > chunk)
				rrb(&top_b);
			else
				rb(&top_b);
		}
	}

//  print_lst(top_a);

}
