/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:01:00 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/09 15:25:20 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Make the list circular
//Shift head by one position forward
//Makes the list non-circular again
void	rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = (*stack);
	while (temp->next)
		temp = temp->next;
	temp->next = (*stack);
	(*stack)->prev = temp;
	(*stack) = (*stack)->next;
	temp = temp->next;
	temp->next = NULL;
	(*stack)->prev = NULL;
}

void	rotate_a(t_stack **stack_a, t_moves **moves)
{
	t_moves	*m;

	rotate(stack_a);
	m = create_move("ra");
	ft_add_move(moves, m);
}

void	rotate_b(t_stack **stack_b, t_moves **moves)
{
	t_moves	*m;

	rotate(stack_b);
	m = create_move("rb");
	ft_add_move(moves, m);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_moves	*m;

	rotate(stack_a);
	rotate(stack_b);
	m = create_move("rr");
	ft_add_move(moves, m);
}
