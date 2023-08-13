/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:25:05 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/13 12:54:47 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	error_handling(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	if (stack_a && (*stack_a))
		ft_free_stack(stack_a);
	if (stack_b && (*stack_b))
		ft_free_stack(stack_b);
	if (moves && (*moves))
		ft_free_moves(moves);
	printf("Error\n");
	exit(1);
}

//Set position of stack elements
void	ft_set_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

//setting the indexes of the stack values
//Helps checking the positions and orders bc you got the smallest value = 1
void	ft_indexation(t_stack *stack_a, int size)
{
	t_stack		*tmp;
	t_stack		*peak;
	int			min;

	while (--size > 0)
	{
		tmp = stack_a;
		peak = NULL;
		min = MIN_INT;
		while (tmp)
		{
			if (tmp->value == MIN_INT && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > min && tmp->index == 0)
			{
				min = tmp->value;
				peak = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		if (peak != NULL)
			peak->index = size;
	}
}

int	get_peak_index(t_stack *stack_a)
{
	int	index;

	index = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index > index)
			index = stack_a->index;
		stack_a = stack_a->next;
	}
	return (index);
}
