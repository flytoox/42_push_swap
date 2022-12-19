/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:18:16 by obelaizi          #+#    #+#             */
/*   Updated: 2022/12/18 00:39:52 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_stack
{
	int				data;
	struct t_stack	*next;
}		t_stack;

t_stack	*ft_stack_new(int content);
void	add_stack_back(t_stack **lst, t_stack *new);
void	add_stack_front(t_stack **lst, t_stack *new);

#endif