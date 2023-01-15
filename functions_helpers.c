/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:50:44 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/16 00:06:54 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_n(t_stack *head, int n)
{
	int	count;

	count = -1;
	while (head)
	{
		if (n == head->data)
			count++;	
		head = head->next;
	}
	return (count);
}

int	check_duplicate(t_stack *a)
{
	t_stack	*node;
	
	node = a;
	while (node)
	{
		if (check_n(a, node->data))
			return(1);
		node = node->next;
	}
	return (0);
}