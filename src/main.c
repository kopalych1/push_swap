/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:22:38 by akostian          #+#    #+#             */
/*   Updated: 2024/09/13 18:36:24 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		if (!argv[1][0])
			return (write(2, "Error\n", 6), 0);
		if (argv[1][0] == ' ')
			return (write(2, "Error\n", 6), 0);
	}
	stack_a.elements = NULL;
	stack_b.elements = NULL;
	if (parse_argv(&stack_a, &stack_b, argc, argv) == -1)
		return (free(stack_a.elements), free(stack_b.elements), -1);
	if (is_sorted(stack_a.elements, stack_a.length))
		return (free(stack_a.elements), free(stack_b.elements), 1);
	if (stack_a.length <= 3)
		sort_three(&stack_a);
	else if (stack_a.length < 50)
		algo_turk(&stack_a, &stack_b);
	else
		algo_min_push(&stack_a, &stack_b);
	return (free(stack_a.elements), free(stack_b.elements), 1);
}
