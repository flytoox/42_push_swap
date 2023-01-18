/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:42:14 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/18 11:12:05 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_num(char *s)
{
	int len;
	int	i;

	len = ft_strlen(s);
	i = -1;
	while (++i < len)
	{
		if ((s[i] == '+' || s[i] == '-') && (s[i + 1] == '+' || s[i + 1] == '-'))
			return (0);
		if (!(ft_isdigit(s[i])) && s[i] != '+' && s[i] != '-' && s[i] != ' ')
			return (0);
	}
	return (1);
}

int	main_parse(char *s, t_stack **head)
{
	char	**res;
	int		i;

	if (!check_num(s))
		return (1);
	res = ft_split(s, ' ');
	i = -1;
	while (res[++i])
	{		
		if (ft_atoi(res[i]) > 2147483647 || ft_atoi(res[i]) < -2147483648)
			return (free_str(res, i), 1);
		add_stack_back(head, ft_stack_new(ft_atoi(res[i]), 0));
	}
	return (free_str(res, i), 0);
}
