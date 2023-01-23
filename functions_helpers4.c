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

void	fill_b_helper(t_stack **top_a, t_stack **top_b, int cnt)
{
	pb(top_a, top_b);
	if (*top_a && (*top_a)->index >= cnt)
	{
		if (scan_last(*top_a, cnt) >= scan_first(*top_a, cnt))
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
		if (scan_last(*top_a, cnt)
			>= scan_first(*top_a, cnt))
			ra(top_a);
		else
			rra(top_a);
	}
	if ((*top_a)->index < cnt - (chunk / 2))
		pb(top_a, top_b);
	else
		fill_b_helper(top_a, top_b, cnt);
}

void	fill_a_helper1(t_stack **top_a, t_stack **top_b, int *check, int *count)
{
	if ((*top_b)->index == *count - 1)
	{
		*check = 1;
		pa(top_a, top_b);
	}
	else
	{
		pa(top_a, top_b);
		*count = *count - 1;
	}
}

void	fill_a_helper2(t_stack **top_a, t_stack **top_b, int *count, int *check)
{
	int	instr_count;
	int	instr_count1;

	instr_count1 = give_me_instr(*top_b, *count - 1);
	instr_count = give_me_instr(*top_b, *count);
	while ((*top_b)->index != *count && (*top_b)->index != *count - 1)
	{
		if (instr_count1 >= instr_count)
		{
			if (get_pos(*top_b, *count) > (ft_lstsize(*top_b) / 2) + 1)
				rrb(top_b);
			else
				rb(top_b);
		}
		else
		{
			if (get_pos(*top_b, *count - 1) > (ft_lstsize(*top_b) / 2) + 1)
				rrb(top_b);
			else
				rb(top_b);
		}
	}
	fill_a_helper1(top_a, top_b, check, count);
}

void	fill_a(t_stack **top_a, t_stack **top_b, int count)
{
	int	check;

	check = 0;
	while (*top_b)
	{
		if (!check)
			fill_a_helper2(top_a, top_b, &count, &check);
		else
		{
			while ((*top_b)->index != count)
			{
				if (get_pos(*top_b, count) > (ft_lstsize(*top_b) / 2) + 1)
					rrb(top_b);
				else
					rb(top_b);
			}
			pa(top_a, top_b);
			sa(top_a);
			count -= 2;
			check = 0;
		}
	}
}
