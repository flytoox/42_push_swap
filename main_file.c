/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:59:05 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/16 15:59:05 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	fill_b(t_stack **top_a, t_stack **top_b, int chunk, int count)
{
	while ((*top_a)->index >= count)
	{
		if (ft_lstsize((*top_a)) - scan_last((*top_a), count) + 1 > scan_first((*top_a), count) - 1)
			ra(top_a);
		else
			rra(top_a);
	}
	if ((*top_a)->index >= count - (chunk / 2))
		pb(top_a, top_b);
	else
	{
		pb(top_a, top_b);
		if ((*top_a) && (*top_a)->index >= count)
		{
			if (ft_lstsize((*top_a)) - scan_last((*top_a), count) + 1 > scan_first((*top_a), count) - 1)
				rr(top_a, top_b);
			else
			{
				rra(top_a);
				rb(top_b);
			}
		}
		else
			rb(top_b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*top_a;
	t_stack	*top_b;
	int		total;
	int		chunk;

	top_a = NULL;
	top_b = NULL;
	if (argc == 1)
		return(printf("cmon do something") ,0);
	while (--argc)
		if (main_parse(*(++argv), &top_a))
			return (printf("error ;)"), ft_lstclear(&top_a), 0);
	if (check_duplicate(top_a))
		return (printf("there is duplicate baby xD"), ft_lstclear(&top_a), 0);
	set_index(top_a, ft_lstsize(top_a));
	total = ft_lstsize(top_a);
	if (total <= 5)
		return (sort_ez(&top_a, &top_b), ft_lstclear(&top_a), ft_lstclear(&top_b), 0);
	else if (total <= 20)
		chunk = total;
	else if (total <= 200)
		chunk = total / 5;
	else if (total == 500)
		chunk = total / 10;
	 else
		chunk = total / 15;
	total = chunk;
	while (top_a)
	{
		if (ft_lstsize(top_b) == total)
			total = total + chunk;
		fill_b(&top_a, &top_b, chunk, total);
	}
	total--;
	while (top_b)
	{
		if (top_b->index == total)
		{
			pa(&top_a, &top_b);
			total--;
		}
		else
		{
			if (get_pos(top_b, total) > (chunk / 2))
				rrb(&top_b);
			else
				rb(&top_b);
		}
	}
	return (ft_lstclear(&top_a), ft_lstclear(&top_b), 0);
}
