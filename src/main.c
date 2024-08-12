/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:22:38 by akostian          #+#    #+#             */
/*   Updated: 2024/08/09 11:39:45 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

#define CHUNK_PERCENTAGE 0.2

double	calc_percentage(int x)
{
	if (x >= 1000)
		return (0.08);
	else if (x >= 500)
		return (0.12);
	else if (x >= 300)
		return (0.18);
	else if (x >= 100)
		return (0.23);
	else if (x <= 5)
		return (1);
	return (0.26);
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc != 2)
		return (ft_printf("ARGC ERROR\n"), -1);
	parse_argv(&stack_a, &stack_b, argv[1]);
	if (is_sorted(stack_a.elements, stack_a.length))
		return (free(stack_a.elements), free(stack_b.elements), 1);
	if (stack_a.length == 2)
	{
		if (stack_a.elements[0] < stack_a.elements[1])
			ft_printf("sa\n");
	}
	else
		sort_algorithm(&stack_a, &stack_b, calc_percentage(stack_a.length));
	return (free(stack_a.elements), free(stack_b.elements), 1);
}
