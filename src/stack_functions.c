/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:16:10 by akostian          #+#    #+#             */
/*   Updated: 2024/08/13 11:32:04 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pa(t_stack *stack_a, t_stack *stack_b, int do_print)
{
	if (stack_b->length < 1)
		return (-1);
	stack_a->elements[stack_a->length]
		= stack_b->elements[stack_b->length - 1];
	stack_a->length += 1;
	stack_b->length -= 1;
	if (do_print)
		ft_printf("pa\n");
	return (0);
}

int	pb(t_stack *stack_a, t_stack *stack_b, int do_print)
{
	if (stack_a->length < 1)
		return (-1);
	stack_b->elements[stack_b->length]
		= stack_a->elements[stack_a->length - 1];
	stack_a->length -= 1;
	stack_b->length += 1;
	if (do_print)
		ft_printf("pb\n");
	return (0);
}

int	ra(t_stack *stack_a, int do_print)
{
	int	tmp;
	int	i;

	i = stack_a->length - 1;
	tmp = stack_a->elements[i];
	while (i > 0)
	{
		stack_a->elements[i] = stack_a->elements[i - 1];
		i--;
	}
	stack_a->elements[i] = tmp;
	if (do_print)
		ft_printf("ra\n");
	return (0);
}

int	rb(t_stack *stack_b, int do_print)
{
	ra(stack_b, 0);
	if (do_print)
		ft_printf("rb\n");
	return (0);
}

int	rr(t_stack *stack_a, t_stack *stack_b, int do_print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (do_print)
		ft_printf("rr\n");
	return (0);
}
