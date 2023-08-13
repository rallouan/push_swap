/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:59:32 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/12 16:47:23 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"
// #include "./libft/libft.h"

void	parse_one_str(t_stack **stack_a, char *argv)
{
	char		**arg_list;
	t_stack		*new;
	long int	num;
	int			i;

	arg_list = ft_split(argv, ' ');
	if (!arg_list)
		error_handling(NULL, NULL, NULL);
	else if (!ft_is_valid_input(arg_list))
		error_handling(NULL, NULL, NULL);
	else
	{
		i = 0;
		while (arg_list[i])
		{
			num = ft_atoi(arg_list[i]);
			if (num > MAX_INT || num < MIN_INT)
				error_handling(stack_a, NULL, NULL);
			new = ft_create_new(num);
			ft_add_end(stack_a, new);
			i++;
		}
	}
}

void	parse_mul_int(t_stack **stack_a, int argc, char **argv)
{
	int			i;
	long int	num;
	t_stack		*new;

	if (!ft_is_valid_input(argv))
		error_handling(NULL, NULL, NULL);
	else
	{
		i = 1;
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			if (num > MAX_INT || num < MIN_INT)
				error_handling(stack_a, NULL, NULL);
			new = ft_create_new(num);
			if (!new)
				error_handling(stack_a, NULL, NULL);
			ft_add_end(stack_a, new);
			i++;
		}
	}
}

t_stack	*parse_args(int argc, char **argv, t_stack	**stack_a)
{
	if (argc < 2)
		error_handling(NULL, NULL, NULL);
	*stack_a = NULL;
	if (argc == 2)
		parse_one_str(stack_a, argv[1]);
	else
		parse_mul_int(stack_a, argc, argv);
	return (*stack_a);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	**stack;

// 	stack = parse_args(argc, argv, stack);
// 	return (0);
// }