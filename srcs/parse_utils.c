/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:00:35 by rallouan          #+#    #+#             */
/*   Updated: 2023/08/13 19:27:16 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// Compares two numbers (in string form)
// returns if they're equal or not (multiple signs included)
int	ft_nbrcmp(char *n1, char *n2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n1[i] == '+')
	{
		if (n2[j] != '+')
			i++;
	}
	else
	{
		if (n2[j] == '+')
			j++;
	}
	while (n1[i] != '\0' && n2[j] != '\0' && n1[i] == n2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)n1[i] - (unsigned char)n2[j]);
}

// checks if the given string is a number or not
// returns 1 if it's a number, 0 if not
int	ft_is_number(char *src)
{
	int	i;

	i = 0;
	if ((src[i] == '-' || src[i] == '+') && src[i + 1] != '\0')
		i++;
	while (src[i] && ft_isdigit(src[i]))
		i++;
	if (src[i] != '\0' && !ft_isdigit(src[i]))
		return (0);
	return (1);
}

//checks for +0 and -0 and 00 and so on 
//to make sure we don't have many zeros in different shapes
//returns 0 if it's not a zero and 1 if it is a zero
int	ft_is_zero(char	*src)
{
	int	i;

	i = 0;
	if (src[i] == '+' || src[i] == '-')
		i++;
	while (src[i] && src[i] == '0')
		i++;
	if (src[i] != '\0')
		return (0);
	return (1);
}

//check if the list of args has duplicates or not
// loop and strcmp elts then check;
int	ft_has_duplicates(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[j])
		{
			if (j != i && ft_nbrcmp(numbers[i], numbers[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//checks the input sequence to see if it's valid
//returns 0 if input is not valid, 1 if it is
//uses ft_has_duplicates and ft_is_zero
int	ft_is_valid_input(char **src)
{
	int	i;
	int	zeros;

	i = 1;
	zeros = 0;
	while (src[i])
	{
		if (!ft_is_number(src[i]))
			return (0);
		zeros += ft_is_zero(src[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (ft_has_duplicates(src))
		return (0);
	return (1);
}
