/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:50:44 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/16 15:48:45 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*tmp;

	if (*b == NULL || (*b)->next == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	node = *b;
	while (node->next->next != NULL)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	tmp->next = *b;
	*b = tmp;
	node = *a;
	while (node->next->next != NULL)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	tmp->next = *a;
	*a = tmp;
	printf("rrr\n");
}

long long int	ft_atoi(const char *str)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r') && *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (999999999999);
		result = result * 10 +(*str - 48);
		str++;
	} 
	return (result * sign);
}

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

int	is_sorted(t_stack *head)
{
	if (!head)
		return (0);
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
