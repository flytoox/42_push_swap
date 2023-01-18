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
	int		total;
	int		chunk;
	int		count;

	top_a = NULL;
	top_b = NULL;
	if (argc == 1)
		return (0);
	while (--argc)
		if (main_parse(*(++argv), &top_a))
			return (ft_putstr("Error\n", 2), ft_lstclear(&top_a), 0);
	if (check_duplicate(top_a))
		return (ft_putstr("Error\n", 2), ft_lstclear(&top_a), 0);
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
	count = chunk;
	while (top_a)
	{
		if (ft_lstsize(top_b) == count)
			count = count + chunk;
		fill_b(&top_a, &top_b, chunk, count);
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
			if (get_pos(top_b, count) > (chunk / 2))
				rrb(&top_b);
			else
				rb(&top_b);
		}
	}
	return (ft_lstclear(&top_a), ft_lstclear(&top_b), 0);
}
