/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:43:05 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/09 17:42:35 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

//Create a new element of type t_stack
t_stack	*ft_create_new(int content)
{
	t_stack	*elt;

	elt = malloc(sizeof(*elt));
	if (!elt)
		return (0);
	elt->value = content;
	elt->position = -1;
	elt->target_pos = -1;
	elt->index = 0;
	elt->cost_a = -1;
	elt->cost_b = -1;
	elt->next = NULL;
	elt->prev = NULL;
	return (elt);
}

//Add new element to the head of the stack
void	ft_add_head(t_stack **stack, t_stack *new)
{
	if (stack)
	{
		new->next = *stack;
		if ((*stack) != NULL)
			(*stack)->prev = new;
		(*stack) = new;
	}
}

//Add a new element to the end of the stack
void	ft_add_end(t_stack **stack, t_stack *new)
{
	t_stack		*temp;

	if (!new)
		return ;
	if (!(*stack))
		ft_add_head(stack, new);
	else
	{
		temp = (*stack);
		if (temp == NULL)
			(*stack) = new;
		else
		{
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
			new->prev = temp;
		}
	}
}

//Get stack size
int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

//Free stack function
void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

// //To be removed
void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}
