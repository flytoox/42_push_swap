/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_func1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:40:47 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/18 22:11:16 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*node;

	if (!(*a) || !((*a)->next))
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = node->next->next;
	(*a)->next = node;
	ft_putstr("sa\n", 1);
}

void	sb(t_stack **b)
{
	t_stack	*node;

	if (!(*b) || !((*b)->next))
		return ;
	node = *b;
	*b = (*b)->next;
	node->next = node->next->next;
	(*b)->next = node;
	ft_putstr("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!(*a) || !((*a)->next) || !(*b) || !((*b)->next))
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = node->next->next;
	(*a)->next = node;
	node = *b;
	*b = (*b)->next;
	node->next = node->next->next;
	(*b)->next = node;
	ft_putstr("ss\n", 1);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b);
	add_stack_front(a, ft_stack_new(tmp->data, tmp->index));
	*b = (*b)->next;
	free(tmp);
	ft_putstr("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a);
	add_stack_front(b, ft_stack_new(tmp->data, tmp->index));
	*a = (*a)->next;
	free(tmp);
	ft_putstr("pb\n", 1);
}
