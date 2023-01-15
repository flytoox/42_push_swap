/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:42:14 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/15 20:55:24 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main_parse(char *s)
{
	int len;
	int	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (!(ft_isdigit(s[i])))
			return (1);
		i++;
	}
	
}