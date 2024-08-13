/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:16:10 by akostian          #+#    #+#             */
/*   Updated: 2024/08/12 21:39:32 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rra(t_stack *stack_a, int do_print)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack_a->elements[i];
	while (i < stack_a->length - 1)
	{
		stack_a->elements[i] = stack_a->elements[i + 1];
		i++;
	}
	stack_a->elements[i] = tmp;
	if (do_print)
		ft_printf("rra\n");
	return (0);
}

int	rrb(t_stack *stack_b, int do_print)
{
	rra(stack_b, 0);
	if (do_print)
		ft_printf("rrb\n");
	return (0);
}

int	rrr(t_stack *stack_a, t_stack *stack_b, int do_print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (do_print)
		ft_printf("rrr\n");
	return (0);
}

int	sa(t_stack *stack_a, int do_print)
{
	int	tmp;

	if (stack_a->length < 2)
		return (-1);
	tmp = stack_a->elements[stack_a->length - 1];
	stack_a->elements[stack_a->length - 1]
		= stack_a->elements[stack_a->length - 2];
	stack_a->elements[stack_a->length - 2] = tmp;
	if (do_print)
		ft_printf("sa\n");
	return (0);
}
