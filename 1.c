/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:36:37 by obelaizi          #+#    #+#             */
/*   Updated: 2022/12/18 15:09:46 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

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
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 +(*str - 48);
		str++;
	}
	return (result * sign);
}

void	print_lst(t_stack *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

int	main(int argc, char *argv[])
{
	int		*tab;
	t_stack	*top_a;
	t_stack	*top_b;
	t_stack	*tmp;
	int		count;

	top_a = NULL;
	top_b = NULL;
	tab = malloc((argc - 1) * 4);
	while (--argc)
		add_stack_back(&top_a, ft_stack_new(ft_atoi(*(++argv))));
	if (top_a->data > top_a->next->data)
		sa(&top_a);
	tmp = top_a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			break ;
		count++;
		tmp = tmp->next;
	}
	while (count--)
		pb(&top_a, &top_b);
}	
