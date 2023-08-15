/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:42:14 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/14 19:50:50 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	execute_moves(char *move, t_stack **stack_a,
			t_stack **stack_b, t_moves **moves)
{
	if (!ft_strncmp(move, "sa\n", 4))
		swap_a(stack_a, moves);
	else if (!ft_strncmp(move, "sb\n", 4))
		swap_b(stack_b, moves);
	else if (!ft_strncmp(move, "ss\n", 4))
		swap_both(stack_a, stack_b, moves);
	else if (!ft_strncmp(move, "pa\n", 4))
		push_a(stack_b, stack_a, moves);
	else if (!ft_strncmp(move, "pb\n", 4))
		push_b(stack_b, stack_a, moves);
	else if (!ft_strncmp(move, "ra\n", 4))
		rotate_a(stack_a, moves);
	else if (!ft_strncmp(move, "rb\n", 4))
		rotate_b(stack_b, moves);
	else if (!ft_strncmp(move, "rr\n", 4))
		rotate_both(stack_a, stack_b, moves);
	else if (!ft_strncmp(move, "rra\n", 4))
		rev_rotate_a(stack_a, moves);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rev_rotate_b(stack_b, moves);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rev_rotate_both(stack_a, stack_b, moves);
	else
		return (0);
	return (1);
}

int	read_moves(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	char	*move;
	int		exec;

	move = get_next_line(0);
	while (move)
	{
		if (!ft_strncmp(move, "\n", 4))
			break ;
		exec = execute_moves(move, stack_a, stack_b, moves);
		free (move);
		if (exec == 0)
			return (0);
		move = get_next_line(0);
	}
	free (move);
	return (exec);
}

void	check(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	int		error;

	error = read_moves(stack_a, stack_b, moves);
	if (error == 0)
		ft_putstr_fd("Error\n", 1);
	else if (is_sorted(*stack_a) && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_moves		*moves;

	stack_a = NULL;
	stack_b = NULL;
	moves = NULL;
	parse_args(argc, argv, &stack_a);
	check(&stack_a, &stack_b, &moves);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	ft_free_moves(&moves);
	return (0);
}
