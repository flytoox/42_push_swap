/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:48:50 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/18 22:10:17 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_last(t_stack *head, int chunk)
{
	while (head)
	{
		if (head->index < chunk)
			return (1);
		head = head->next;
	}
	return (0);
}

int	scan_last(t_stack *head, int chunk)
{
	int	count;

	count = 0;
	while (is_last(head, chunk))
	{
		head = head->next;
		count++;
	}
	return (count);
}

int	scan_first(t_stack *head, int chunk)
{
	int	count;

	count = 1;
	while (head)
	{
		if (head->index < chunk)
			return (count);
		head = head->next;
		count++;
	}
	return (count);
}

int	get_pos(t_stack *head, int index)
{
	int	count;

	count = 1;
	while (head)
	{
		if (head->index == index)
			return (count);
		head = head->next;
		count++;
	}
	return (0);
}

int	get_min(t_stack *head, int check)
{
	int		tmp;

	tmp = head->data;
	while (head && tmp <= check)
	{
		tmp = head->data;
		head = head->next;
	}
	while (head)
	{
		if (head->data <= check)
		{
			head = head->next;
			continue ;
		}
		if (head->data < tmp)
			tmp = head->data;
		head = head->next;
	}
	return (tmp);
}
