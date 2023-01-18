/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:48:02 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/18 12:57:11 by obelaizi         ###   ########.fr       */
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
