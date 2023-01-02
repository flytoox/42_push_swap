/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:11:33 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/01 19:17:03 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int content, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->index = index;
	node->data = content;
	node->next = 0;
	return (node);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*i;
	int		count;

	if (!lst)
		return (0);
	count = 0;
	i = lst;
	while (i)
	{
		count++;
		i = i->next;
	}
	return (count);
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

t_stack	*get_stack_last(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	sa(t_stack *a)
{
	t_stack	*node;
	int		tmp;

	if (!a || !(a->next))
		return ;
	node = a;
	tmp = node->data;
	node->data = node->next->data;
	node->next->data = tmp;
	printf("sa\n");
}

void	sb(t_stack *b)
{
	t_stack	*node;
	int		tmp;

	if (!b || !(b->next))
		return ;
	node = b;
	tmp = node->data;
	node->data = node->next->data;
	node->next->data = tmp;
	printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
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
	add_stack_front(a, ft_stack_new(tmp->data, tmp->index));
	*b = (*b)->next;
	free(tmp);
	printf("pa\n");

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
	printf("pb\n");
}

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
	ra(a);
	rb(b);
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

void	rrr(t_stack *a, t_stack *b)
{
	rra(&a);
	rrb(&b);
}

