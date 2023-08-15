/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:08:47 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/14 11:41:41 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MIN_INT -2147483648
# define MAX_INT 2147483647

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../bonus/get_next_line/get_next_line.h"

/*
value     : the number entered
position  : current placement of the element in the stack
target_pos: placement where elt should be to be sorted
cost_a    : position changes needed to get to target pos in stack_a
cost_b    : position changes needed to get to top of stack_b
index     : order of number in the nums entered (0 being the smallest)
next      : pointer to the next elt in the list
prev      : pointer to the previous elt in the list
*/
typedef struct s_stack
{
	int					value;
	int					position;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	int					index;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

/*
move : name of the move done
next : pointer to the next move in the list
prev : pointer to the previous move in the list
*/
typedef struct s_moves
{
	char			*move;
	struct s_moves	*next;
	struct s_moves	*prev;
}	t_moves;

//Parsing functions
t_stack		*parse_args(int argc, char **argv, t_stack	**stack_a);
void		parse_mul_int(t_stack **stack_a, int argc, char **argv);
void		parse_one_str(t_stack **stack_a, char *argv);

//Checking input validity (Parsing utils)
int			ft_is_valid_input(char **src);
int			ft_has_duplicates(char **numbers);
int			ft_is_zero(char	*src);
int			ft_is_number(char *src);
int			ft_nbrcmp(char *n1, char *n2);

//list operations
t_stack		*ft_create_new(int content);
void		ft_add_head(t_stack **stack, t_stack *new);
void		ft_add_end(t_stack **stack, t_stack *new);
int			ft_stack_size(t_stack *stack);
void		ft_free_stack(t_stack **stack);
// void		ft_print_stack(t_stack *stack);

//moves operations
t_moves		*create_move(char *move);
void		ft_add_move(t_moves **moves, t_moves *new);
void		remove_move(t_moves **moves, t_moves *m);
void		ft_print_moves(t_moves *moves);
void		ft_free_moves(t_moves **moves);

//push functions
void		push(t_stack **from, t_stack **to);
void		push_a(t_stack **stack_b, t_stack **stack_a, t_moves **moves);
void		push_b(t_stack **stack_b, t_stack **stack_a, t_moves **moves);

//swap functions
void		swap(t_stack **stack);
void		swap_a(t_stack **stack_a, t_moves **moves);
void		swap_b(t_stack **stack_b, t_moves **moves);
void		swap_both(t_stack **stack_a, t_stack **stack_b, t_moves **moves);

//rotate functions
void		rotate(t_stack **stack);
void		rotate_a(t_stack **stack_a, t_moves **moves);
void		rotate_b(t_stack **stack_b, t_moves **moves);
void		rotate_both(t_stack **stack_a, t_stack **stack_b, t_moves **moves);

//reverse rotate functions
void		rev_rotate(t_stack **stack);
void		rev_rotate_a(t_stack **stack_a, t_moves **moves);
void		rev_rotate_b(t_stack **stack_b, t_moves **moves);
void		rev_rotate_both(t_stack **stack_a,
				t_stack **stack_b, t_moves **moves);

//stack_related functions
void		error_handling(t_stack **stack_a,
				t_stack **stack_b, t_moves **moves);
void		ft_set_pos(t_stack **stack);
void		ft_indexation(t_stack	*stack_a, int size);
int			get_peak_index(t_stack *stack_a);

//position related funcitons
int			ft_min_index_pos(t_stack **stack);
int			ft_get_target_pos(t_stack **stack_a, int index_b,
				int target_index, int target_pos);
void		ft_get_all_targets(t_stack **stack_a, t_stack **stack_b);
void		set_cost(t_stack **stack_a, t_stack **stack_b);
void		cost_effective_move(t_stack **stack_a,
				t_stack **stack_b, t_moves **moves);

//Sorting functions
void		sort(t_stack **stack_a, t_stack **stack_b,
				t_moves **moves, int size);
void		sort_big(t_stack **stack_a, t_stack **stack_b,
				t_moves **moves);
void		sort_three(t_stack **stack_a, t_moves **moves);

//Sorting utils
int			is_sorted(t_stack *stack);
void		ft_leave_three(t_stack **stack_a,
				t_stack **stack_b, t_moves **moves);
void		fix_stack(t_stack **stack_a, t_moves **moves);

//Cost moves
void		cost_moves(t_stack **stack_a, t_stack **stack_b,
				int *costs, t_moves **moves);
#endif