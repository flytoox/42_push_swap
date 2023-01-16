/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:37:44 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/16 15:54:54 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstclear(t_stack **lst)
{
	int		size;
	t_stack	*tmp;

	if (!(*lst))
		return ;
	size = ft_lstsize(*lst);
	while (size--)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

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

void	add_stack_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
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
