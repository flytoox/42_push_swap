/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_func1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:40:47 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/18 12:03:05 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_stack **a)
{
	t_stack	*node;

	if (!(*a) || !((*a)->next))
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = node->next->next;
	(*a)->next = node;
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
}