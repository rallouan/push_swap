/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:26:26 by rallouan          #+#    #+#             */
/*   Updated: 2023/07/30 14:30:15 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (! (*from))
		return ;
	temp = (*from)->next;
	(*from)->next = *to;
	(*from)->prev = NULL;
	if (*to)
		(*to)->prev = (*from);
	*to = *from;
	*from = temp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_moves	*m;

	m = NULL;
	push(stack_a, stack_b);
	m = create_move("pa");
	ft_add_move(moves, m);
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_moves	*m;

	m = NULL;
	push(stack_b, stack_a);
	m = create_move("pb");
	ft_add_move(moves, m);
}
