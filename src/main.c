/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:22:38 by akostian          #+#    #+#             */
/*   Updated: 2024/08/15 16:29:41 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc == 2)
		return (1);
	if (parse_argv(&stack_a, &stack_b, argc, argv) == -1)
		return (free(stack_a.elements), free(stack_b.elements), -1);
	if (is_sorted(stack_a.elements, stack_a.length))
		return (free(stack_a.elements), free(stack_b.elements), 1);
	if (stack_a.length <= 3)
		sort_three(&stack_a);
	else if (stack_a.length < 50)
		sort_algorithm(&stack_a, &stack_b);
	else
		sort_algorithm2(&stack_a, &stack_b);
	return (free(stack_a.elements), free(stack_b.elements), 1);
}
