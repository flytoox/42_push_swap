/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:41:06 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/18 22:09:40 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	return (-1);
}

int	contain_nl(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '\n')
		return (1);
	return (0);
}

int	check_func(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa\n"))
		return (sa(a), 1);
	else if (!ft_strcmp(str, "sb\n"))
		return (sb(b), 1);
	else if (!ft_strcmp(str, "ss\n"))
		return (ss(a, b), 1);
	else if (!ft_strcmp(str, "pa\n"))
		return (pa(a, b), 1);
	else if (!ft_strcmp(str, "pb\n"))
		return (pb(a, b), 1);
	else if (!ft_strcmp(str, "ra\n"))
		return (ra(a), 1);
	else if (!ft_strcmp(str, "rb\n"))
		return (rb(b), 1);
	else if (!ft_strcmp(str, "rr\n"))
		return (rr(a, b), 1);
	else if (!ft_strcmp(str, "rra\n"))
		return (rra(a), 1);
	else if (!ft_strcmp(str, "rrb\n"))
		return (rrb(b), 1);
	else if (!ft_strcmp(str, "rrr\n"))
		return (rrr(a, b), 1);
	else
		return (ft_putstr("Error\n", 2), 0);
}

int	handle_me_pls(int argc, char *argv[], t_stack **top_a)
{
	if (argc == 1)
		return (0);
	while (--argc)
		if (main_parse(*(++argv), top_a))
			return (ft_putstr("Error\n", 2), ft_lstclear(top_a), 0);
	if (check_duplicate(*top_a))
		return (ft_putstr("Error\n", 2), ft_lstclear(top_a), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*top_a;
	t_stack	*top_b;
	char	*bf;

	top_a = NULL;
	top_b = NULL;
	if (!handle_me_pls(argc, argv, &top_a))
		return (0);
	bf = get_next_line(0);
	while (bf)
	{
		if (!check_func(bf, &top_a, &top_b))
			return (free(bf), ft_lstclear(&top_a), ft_lstclear(&top_b), 0);
		free(bf);
		bf = get_next_line(0);
	}
	if (is_sorted(top_a) && !top_b)
		return (ft_putstr("OK\n", 1), free(bf),
			ft_lstclear(&top_a), ft_lstclear(&top_b), 0);
	return (ft_putstr("KO\n", 1), free(bf),
		ft_lstclear(&top_a), ft_lstclear(&top_b), 0);
}
