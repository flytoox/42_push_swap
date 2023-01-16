/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:40:42 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/16 15:42:08 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	node = *a;
	while (node->next != NULL)
		node = node->next;
	node->next = tmp;
	tmp->next = NULL;
	printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	node = *b;
	while (node->next != NULL)
		node = node->next;
	node->next = tmp;
	tmp->next = NULL;
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*node;
	t_stack	*tmp1;
	t_stack	*node1;

	if (*b == NULL || (*b)->next == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	node = *a;
	tmp1 = *b;
	*b = (*b)->next;
	node1 = *b;
	while (node->next != NULL)
		node = node->next;
	while (node1->next != NULL)
		node1 = node1->next;
	node->next = tmp;
	tmp->next = NULL;
	node1->next = tmp1;
	tmp1->next = NULL;
	printf("rr\n");
}

void rra(t_stack **a)
{
	t_stack	*node;
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = *a;
	while (node->next->next != NULL)
	{
		node = node->next;
	}

	tmp = node->next;

	node->next = NULL;

	tmp->next = *a;
	*a = tmp;
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*node;
	t_stack	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next->next != NULL)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	tmp->next = *b;
	*b = tmp;
	printf("rrb\n");
}
