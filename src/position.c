/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:43:02 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/13 15:12:47 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Returns the position of the elt with smallest index
int	ft_min_index_pos(t_stack **stack)
{
	t_stack		*tmp;
	int			min_index;
	int			min_pos;

	tmp = *stack;
	min_index = MAX_INT;
	ft_set_pos(stack);
	min_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

/*
Get target position of a specific element from stack_b in stack_a
- Checks if the index of elt stack_b can be put between elts of stack_a
- Does so by checking if there is an element in stack_a with a bigger index
- Otherwise it finds the elt with the smallest index in stack_a
- That is your target position
*/
int	ft_get_target_pos(t_stack **stack_a, int index_b,
		int target_index, int target_pos)
{
	t_stack		*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	if (target_index != MAX_INT)
		return (target_pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

//get target position for all elements of stack_b
//The segfault is happening here I guess
void	ft_get_all_targets(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp;
	int			target;

	tmp = *stack_b;
	ft_set_pos(stack_a);
	ft_set_pos(stack_b);
	target = 0;
	while (tmp)
	{
		target = ft_get_target_pos(stack_a, tmp->index, MAX_INT, target);
		tmp->target_pos = target;
		tmp = tmp->next;
	}
}

/*
- Calculates the cost of getting each elt in stack_b to its target pos in stack_a
- cost_b = cost of getting elt to the top of stack_b
- cost_a = cost of getiing elt from top of b to target position in stack_a

if elt is in the top half, cost > 0;
if elt is in the bottom half, cost < 0;
*/
void	set_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	int			size_a;
	int			size_b;

	tmp_a = (*stack_a);
	tmp_b = (*stack_b);
	size_a = ft_stack_size(*stack_a);
	size_b = ft_stack_size(*stack_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > (size_b / 2))
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > (size_a / 2))
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

//finds most cost effective move and does it
void	cost_effective_move(t_stack **stack_a,
			t_stack **stack_b, t_moves **moves)
{
	t_stack		*tmp;
	int			best;
	int			costs[2];
	// int			sum_cost;

	// ft_print_stack(*stack_b);
	// ft_print_stack(*stack_a);
	tmp = (*stack_b);
	best = MAX_INT;
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < abs(best))
		{
			best = abs(tmp->cost_b) + abs(tmp->cost_a);
			costs[0] = tmp->cost_a;
			costs[1] = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	cost_moves(stack_a, stack_b, costs, moves);
}
