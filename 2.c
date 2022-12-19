/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:11:33 by obelaizi          #+#    #+#             */
/*   Updated: 2022/12/18 12:27:22 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->data = content;
	node->next = 0;
	return (node);
}

void	add_stack_back(t_stack **lst, t_stack *new)
{
	t_stack	*check;

	if (!new)
		return ;
	if (!(*lst))
	{
		add_stack_front(lst, new);
		return ;
	}
	check = *lst;
	while (check->next)
		check = check->next;
	check->next = new;
}

void	add_stack_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	sa(t_stack **a)
{
	t_stack	*node;
	int		tmp;

	if (!(*a) || !(*a)->next)
		return ;
	node = (*a);
	tmp = node->data;
	node->data = node->next->data;
	node->next->data = tmp;
}

void	sb(t_stack **b)
{
	t_stack	*node;
	int		tmp;

	if (!(*b) || !(*b)->next)
		return ;
	node = (*b);
	tmp = node->data;
	node->data = node->next->data;
	node->next->data = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b);
	add_stack_front(a, ft_stack_new(tmp->data));
	*b = (*b)->next;
	free(tmp);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a);
	add_stack_front(b, ft_stack_new(tmp->data));
	*a = (*a)->next;
	free(tmp);
}

void	ra(t_stack *a)
{
	t_stack	*node;
	int		first;

	node = a;
	first = node->data;
	while (node->next)
	{
		node->data = node->next->data;
		node = node->next;
	}
	node->data = first;
}

void	rb(t_stack *b)
{
	t_stack	*node;
	int		first;

	node = b;
	first = node->data;
	while (node->next)
	{
		node->data = node->next->data;
		node = node->next;
	}
	node->data = first;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_stack	*node;
	int		previous;
	int		tmp;	

	node = a;
	previous = node->data;
	node = node->next;
	while (node)
	{
		tmp = node->data;
		node->data = previous;
		previous = tmp;
		node = node->next;
	}
	a->data = previous;
}

void	rrb(t_stack *b)
{
	t_stack	*node;
	int		previous;
	int		tmp;	

	node = b;
	previous = node->data;
	node = node->next;
	while (node)
	{
		tmp = node->data;
		node->data = previous;
		previous = tmp;
		node = node->next;
	}
	b->data = previous;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

