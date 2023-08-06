/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:09:46 by rallouan          #+#    #+#             */
/*   Updated: 2023/07/30 14:30:06 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Make it circular then shift by one back (last elt becomes first) the unlink
void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = (*stack);
	while (temp->next)
		temp = temp->next;
	temp->next = (*stack);
	(*stack)->prev = temp;
	(*stack) = temp;
	temp = temp->prev;
	temp->next = NULL;
	(*stack)->prev = NULL;
}

void	rev_rotate_a(t_stack **stack_a, t_moves **moves)
{
	t_moves	*m;

	rev_rotate(stack_a);
	m = create_move("rra");
	ft_add_move(moves, m);
}

void	rev_rotate_b(t_stack **stack_a, t_moves **moves)
{
	t_moves	*m;

	rev_rotate(stack_a);
	m = create_move("rrb");
	ft_add_move(moves, m);
}

void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_moves	*m;

	rev_rotate(stack_a);
	rev_rotate(stack_b);
	m = create_move("rrr");
	ft_add_move(moves, m);
}
