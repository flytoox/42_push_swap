/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:48:02 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/18 14:39:22 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(const char *s, int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return ;
	}
	write(fd, s, ft_strlen(s));
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
