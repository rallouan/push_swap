/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:33:40 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/06 15:50:41 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
Push all elements from stack_a to stack_b
Leaves 3 elements in stack_a
Pushes smaller values first to help with the rest of the sorting
Uses a dichotomic thingy to ensure that
AKA, if the index is smaller than 1/2 the size only then you push
Otherwise you rotate stack_a
*/
void	ft_leave_three(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	int		size;
	int		pushed;
	int		i;

	size = ft_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < (size / 2))
	{
		if ((*stack_a)->index <= (size / 2))
		{
			push_b(stack_a, stack_b, moves);
			pushed++;
		}
		else
			rotate_a(stack_a, moves);
		i++;
	}
	while (size - pushed > 3)
	{
		push_b(stack_a, stack_b, moves);
		pushed++;
	}
}

/*
Finds the position of the lowest index in the stack
If it's in the upper half --> rotate
if it's in the lower half --> rev rotate
Keep doing so until elt with the lowest index is on the top of stack_a
*/
void	fix_stack(t_stack **stack_a, t_moves **moves)
{
	int		size;
	int		min_pos;

	size = ft_stack_size(*stack_a);
	min_pos = ft_min_index_pos(stack_a);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rev_rotate_a(stack_a, moves);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			rotate_a(stack_a, moves);
			min_pos--;
		}
	}
}
