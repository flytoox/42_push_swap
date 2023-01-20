/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:53:15 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/20 20:49:31 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b_helper(t_stack **top_a, t_stack **top_b, int *cnt)
{
	pb(top_a, top_b);
	if (*top_a && (*top_a)->index >= *cnt)
	{
		if (ft_lstsize(*top_a) - scan_last(*top_a, *cnt)
			+ 1 >= scan_first(*top_a, *cnt) - 1)
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

void	fill_b(t_stack **top_a, t_stack **top_b, int chunk, int cnt)
{
	while ((*top_a)->index >= cnt)
	{
		if (ft_lstsize(*top_a) - scan_last(*top_a, cnt)
			+ 1 >= scan_first(*top_a, cnt) - 1)
			ra(top_a);
		else
			rra(top_a);
	}
	if ((*top_a)->index > cnt - (chunk / 2))
		pb(top_a, top_b);
	else
		fill_b_helper(top_a, top_b, &cnt);
}

void	fill_a_helper(t_stack **top_a, t_stack **top_b, int *check, int *count)
{
	pa(top_a, top_b);
	if (*check)
	{
		sa(top_a);
		*count -= 2;
		*check = 0;
	}
	else
		*count = *count - 1;
}

void	fill_a(t_stack **top_a, t_stack **top_b, int chunk, int count)
{
	int	check;

	check = 0;
	while (*top_b)
	{
		if ((*top_b)->index == count - 1)
		{
			pa(top_a, top_b);
			check = 1;
		}
		if ((*top_b)->index == count)
			fill_a_helper(top_a, top_b, &check, &count);
		else
		{
			if (get_pos(*top_b, count) > (chunk / 2))
				rrb(top_b);
			else
				rb(top_b);
		}
	}
}
