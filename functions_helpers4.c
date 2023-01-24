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
		rr(top_a, top_b);
	else
		rb(top_b);
}

void	fill_b(t_stack **top_a, t_stack **top_b, int chunk, int *cnt)
{
	while ((*top_a)->index >= *cnt)
		ra(top_a);
	if ((*top_a)->index < *cnt - (chunk / 2))
		pb(top_a, top_b);
	else
		fill_b_helper(top_a, top_b, *cnt);
	if (ft_lstsize(*top_b) == *cnt)
		*cnt = *cnt + chunk;
}

void	push_cnt(t_stack **a, t_stack **b, int count)
{
	while ((*b)->index != count)
	{
		if (get_pos(*b, count) > (ft_lstsize(*b) / 2) + 1)
			rrb(b);
		else
			rb(b);
	}
	pa(a, b);
}

void	push_cnt1(t_stack **a, t_stack **b, int count)
{
	while ((*b)->index != count - 1)
	{
		if (get_pos(*b, count - 1) > (ft_lstsize(*b) / 2) + 1)
			rrb(b);
		else
			rb(b);
	}
	pa(a, b);
	push_cnt(a, b, count);
	sa(a);
}

void	fill_a(t_stack **top_a, t_stack **top_b, int count)
{
	int	instr_count;
	int	instr_count1;

	while (*top_b)
	{
		instr_count1 = give_me_instr(*top_b, count - 1);
		instr_count = give_me_instr(*top_b, count);
		if (instr_count1 >= instr_count || instr_count1 == -1)
		{
			push_cnt(top_a, top_b, count);
			count -= 1;
		}
		else
		{
			push_cnt1(top_a, top_b, count);
			count -= 2;
		}
	}
}
