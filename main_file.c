/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:59:05 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/16 15:59:05 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_me_pls(int argc, char *argv[], t_stack **top_a)
{
	if (argc == 1)
		return (0);
	while (--argc)
		if (main_parse(*(++argv), top_a))
			return (ft_putstr("Error\n", 2), ft_lstclear(top_a), 0);
	if (check_duplicate(*top_a))
		return (ft_putstr("Error\n", 2), ft_lstclear(top_a), 0);
	if (is_sorted(*top_a))
		return (ft_lstclear(top_a), 0);
	set_index(*top_a, ft_lstsize(*top_a));
	return (1);
}

int	give_me_that_chunck(int total)
{
	int	chunk;

	if (total <= 20)
		chunk = total;
	else if (total <= 200)
		chunk = total / 5;
	else if (total <= 500)
		chunk = total / 9;
	else
		chunk = total / 15;
	return (chunk);
}

int	give_me_instr(t_stack *head, int index)
{
	if (get_pos(head, index) > (ft_lstsize(head) / 2))
		return (ft_lstsize(head) - (get_pos(head, index) - 1));
	return (get_pos(head, index) - 1);
}

int	main(int argc, char *argv[])
{
	t_stack	*top_a;
	t_stack	*top_b;
	int		chunk;
	int		count;

	top_a = NULL;
	top_b = NULL;
	if (!handle_me_pls(argc, argv, &top_a))
		return (1);
	if (ft_lstsize(top_a) <= 5)
		return (sort_ez(&top_a, &top_b),
			ft_lstclear(&top_a), ft_lstclear(&top_b), 0);
	chunk = give_me_that_chunck(ft_lstsize(top_a));
	count = chunk;
	while (top_a)
	{
		if (ft_lstsize(top_b) == count)
			count = count + chunk;
		fill_b(&top_a, &top_b, chunk, count);
	}
	fill_a(&top_a, &top_b, ft_lstsize(top_b) - 1);
	return (ft_lstclear(&top_a), ft_lstclear(&top_b), 0);
}
