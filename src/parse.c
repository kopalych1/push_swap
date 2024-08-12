/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:57:37 by akostian          #+#    #+#             */
/*   Updated: 2024/08/06 07:58:34 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_stacks(t_stack *stack_a, t_stack *stack_b, int length)
{
	stack_a->length = length;
	stack_b->length = 0;
	stack_a->elements = (int *)malloc(sizeof(int) * length);
	stack_b->elements = (int *)malloc(sizeof(int) * length);
	if (!stack_a->elements || !stack_b->elements)
		return (ft_printf("MALLOC ERROR\n"), 0);
	return (1);
}

int	parse_argv(t_stack *stack_a, t_stack *stack_b, char *argv)
{
	char	**splited;
	int		i;
	int		length;

	splited = ft_split(argv, ' ');
	i = -1;
	while (splited[++i])
		if (!ft_atoi(splited[i]) && splited[i][0] != '0')
			return (ft_printf("SPLIT ERROR\n"), -1);
	length = i;
	if (!init_stacks(stack_a, stack_b, length))
		return (0);
	i = 0;
	while (i < length)
	{
		if (is_in_array(ft_atoi(splited[length - i - 1]),
				stack_a->elements, i))
			return (ft_printf("DUPLICATE ERROR\n"), -1);
		stack_a->elements[i] = ft_atoi(splited[length - i - 1]);
		free(splited[length - i - 1]);
		i++;
	}
	free(splited);
	return (1);
}
