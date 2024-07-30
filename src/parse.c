/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:57:37 by akostian          #+#    #+#             */
/*   Updated: 2024/07/30 15:52:22 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	parse_argv(t_stack *stack_a, t_stack *stack_b, char *argv)
{
	char	**splited;
	int		i;

	splited = ft_split(argv, ' ');
	i = -1;
	while (splited[++i])
		if (!ft_atoi(splited[i]))
			return (ft_printf("SPLIT ERROR\n"), -1);
	stack_a->length = i;
	stack_b->length = 0;
	stack_a->elements = malloc(sizeof(int) * stack_a->length);
	stack_b->elements = malloc(sizeof(int) * stack_a->length);
	if (!stack_a->elements || !stack_b->elements)
		return (ft_printf("MALLOC ERROR\n"), -1);
	i = -1;
	while (++i < stack_a->length)
	{
		if (is_in_array(ft_atoi(splited[i]),
				stack_a->elements, stack_a->length))
			return (ft_printf("DUPLICATE ERROR\n"), -1);
		stack_a->elements[i] = ft_atoi(splited[i]);
		free(splited[i]);
	}
	free(splited);
	return (1);
}
