/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:22:38 by akostian          #+#    #+#             */
/*   Updated: 2024/07/30 15:52:46 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc != 2)
		return (ft_printf("ARGC ERROR\n"), -1);
	parse_argv(&stack_a, &stack_b, argv[1]);
	i = -1;
	ft_printf("Stack A: \n", i, stack_a.elements[i]);
	while (++i < stack_a.length)
		ft_printf("i: %d\t element: %d\n", i, stack_a.elements[i]);
	i = -1;
	free(stack_a.elements);
	free(stack_b.elements);
}
