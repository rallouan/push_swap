/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:03:45 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/06 15:52:41 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		**stack_a;
	t_stack		**stack_b;
	t_moves		**moves;
	int			size;

	stack_b = NULL;
	moves = NULL;
	stack_a = parse_args(argc, argv, stack_a);
	size = ft_stack_size(*stack_a);
	ft_indexation(stack_a, size + 1);
	sort(stack_a, stack_b, moves, size);
	ft_print_moves(*moves);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	ft_free_moves(moves);
	return (0);
}
