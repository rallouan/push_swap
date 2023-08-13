/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:33:07 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/13 15:11:22 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a, t_moves **moves)
{
	int		peak;

	if (is_sorted(*stack_a))
		return ;
	peak = get_peak_index(*stack_a);
	if ((*stack_a)->index == peak)
		rotate_a(stack_a, moves);
	else if ((*stack_a)->next->index == peak)
		rev_rotate_a(stack_a, moves);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a, moves);
}

/*
- Push all elements to b except three, sort the three
- Get target position of each element of b
- Calculate the cost of going from current position to target position
- Do the shift that requires the least moves (cost)
- If the stack is not sorted shift it
*/
void	sort_big(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	ft_leave_three(stack_a, stack_b, moves);
	sort_three(stack_a, moves);
	while (*stack_b)
	{
		ft_get_all_targets(stack_a, stack_b);
		set_cost(stack_a, stack_b);
		cost_effective_move(stack_a, stack_b, moves);
	}
	if (!is_sorted(*stack_a))
		fix_stack(stack_a, moves);
}

void	sort(t_stack **stack_a, t_stack **stack_b, t_moves **moves, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		swap_a(stack_a, moves);
	else if (size == 3 && !is_sorted(*stack_a))
		sort_three(stack_a, moves);
	else if (size > 3 && !is_sorted(*stack_a))
		sort_big(stack_a, stack_b, moves);
}
