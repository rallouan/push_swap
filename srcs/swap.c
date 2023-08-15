/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:03:24 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/07 20:47:13 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*elt_1;
	t_stack	*elt_2;

	if (!(*stack) || !(*stack)->next)
		return ;
	elt_1 = (*stack);
	elt_2 = (*stack)->next;
	if (elt_2->next)
		elt_2->next->prev = elt_1;
	elt_1->prev = elt_2;
	elt_2->prev = NULL;
	elt_1->next = elt_2->next;
	elt_2->next = elt_1;
	*stack = elt_2;
}

void	swap_a(t_stack **stack_a, t_moves **moves)
{
	t_moves	*m;

	swap(stack_a);
	m = create_move("sa");
	ft_add_move(moves, m);
}

void	swap_b(t_stack **stack_b, t_moves **moves)
{
	t_moves	*m;

	swap(stack_b);
	m = create_move("sb");
	ft_add_move(moves, m);
}

void	swap_both(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_moves	*m;

	swap(stack_a);
	swap(stack_b);
	m = create_move("ss");
	ft_add_move(moves, m);
}
