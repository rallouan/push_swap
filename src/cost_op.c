/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:17:28 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/13 16:35:28 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//All these functions are static because they're only used in this file

//Rev rotates the stacks until one of them is in position
static void	cost_rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
			int *costs, t_moves **moves)
{
	while (costs[0] > 0 && costs[1] > 0)
	{
		(costs[0])--;
		(costs[1])--;
		rev_rotate_both(stack_a, stack_b, moves);
	}
}

//Rotates both stacks until one of them in position
static void	cost_rotate_both(t_stack **stack_a, t_stack **stack_b,
			int *costs, t_moves **moves)
{
	while (costs[0] > 0 && costs[1] > 0)
	{
		(costs[0])--;
		(costs[1])--;
		rotate_both(stack_a, stack_b, moves);
	}
}

//Rotates stack_a until the elt reaches the top(rev if neg)
static void	cost_rotate_a(t_stack **stack_a, t_moves **moves, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			rotate_a(stack_a, moves);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rev_rotate_a(stack_a, moves);
			(*cost_a)++;
		}
	}
}

//Rotates stack_b until the elt reaches the top(rev if neg)
static void	cost_rotate_b(t_stack **stack_b, t_moves **moves, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rotate_b(stack_b, moves);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rev_rotate_b(stack_b, moves);
			(*cost_b)++;
		}
	}
}

/*
If cost_a and cost_b are both negative you reverse rotate both
If both are positive you rotate both
Then rotate_ and rotate_b then push to a
*/
void	cost_moves(t_stack **stack_a, t_stack **stack_b,
				int *costs, t_moves **moves)
{
	if (costs[0] < 0 && costs[1] < 0)
		cost_rev_rotate_both(stack_a, stack_b, costs, moves);
	else if (costs[0] > 0 && costs[1] > 0)
		cost_rotate_both(stack_a, stack_b, costs, moves);
	cost_rotate_a(stack_a, moves, &costs[0]);
	cost_rotate_b(stack_b, moves, &costs[1]);
	push_a(stack_a, stack_b, moves);
}
