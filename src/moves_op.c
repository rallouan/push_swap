/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:32 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/13 18:11:28 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_moves	*create_move(char *move)
{
	t_moves	*m;

	m = malloc(sizeof(*m));
	if (!m)
		return (0);
	m->move = move;
	m->next = NULL;
	m->prev = NULL;
	return (m);
}

void	ft_add_move(t_moves **moves, t_moves *new)
{
	t_moves		*temp;

	if (!new)
		return ;
	if (!(*moves))
		(*moves) = new;
	else
	{
		temp = (*moves);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void	remove_move(t_moves **moves, t_moves *m)
{
	t_moves	*current;

	if (!moves || !(*moves))
		return ;
	current = *moves;
	while (current && (current != m))
		current = current->next;
	if (! current)
		return ;
	if (current == (*moves))
	{
		(*moves) = current->next;
		if (*moves)
			(*moves)->prev = NULL;
	}
	else
	{
		current->prev->next = current->next;
		if (current->next)
			current->next->prev = current->prev;
	}
	free (current);
}

void	ft_print_moves(t_moves *moves)
{
	while (moves)
	{
		ft_putstr_fd(moves->move, 1);
		ft_putstr_fd("\n", 1);
		moves = moves->next;
	}
}

void	ft_free_moves(t_moves **moves)
{
	t_moves	*tmp;

	if (!moves || !(*moves))
		return ;
	tmp = *moves;
	while (*moves)
	{
		tmp = (*moves)->next;
		free(*moves);
		*moves = tmp;
	}
}
