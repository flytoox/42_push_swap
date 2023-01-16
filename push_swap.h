/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:18:16 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/08 19:52:09 by obelaizi         ###   ########.fr       */
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
	int				index;
	struct t_stack	*next;
}		t_stack;

int	main_parse(char *s, t_stack **head);
int	check_duplicate(t_stack *a);
int	is_sorted(t_stack *head);
int	scan_last(t_stack *head, int chunk);
int	scan_first(t_stack *head, int chunk);
int	get_pos(t_stack *head, int index);
int	get_min(t_stack *head, int check);

int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	free_str(char **str, int i);

char	**ft_split(char const *s, char c);
long long int	ft_atoi(const char *str);

t_stack	*ft_stack_new(int content, int index);
void	add_stack_back(t_stack **lst, t_stack *new);
void	add_stack_front(t_stack **lst, t_stack *new);
int	ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst);


void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);



#endif