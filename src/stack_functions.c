/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:16:10 by akostian          #+#    #+#             */
/*   Updated: 2024/08/06 07:59:02 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->elements[stack_a->length]
		= stack_b->elements[stack_b->length - 1];
	stack_a->length += 1;
	stack_b->length -= 1;
	ft_printf("pa\n");
	return (0);
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->elements[stack_b->length]
		= stack_a->elements[stack_a->length - 1];
	stack_a->length -= 1;
	stack_b->length += 1;
	ft_printf("pb\n");
	return (0);
}

int	ra(t_stack *stack_a)
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
	ft_printf("ra\n");
	return (0);
}

int	rb(t_stack *stack_b)
{
	int	tmp;
	int	i;

	i = stack_b->length - 1;
	tmp = stack_b->elements[i];
	while (i > 0)
	{
		stack_b->elements[i] = stack_b->elements[i - 1];
		i--;
	}
	stack_b->elements[i] = tmp;
	ft_printf("rb\n");
	return (0);
}

int	rrb(t_stack *stack_b)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack_b->elements[i];
	while (i < stack_b->length - 1)
	{
		stack_b->elements[i] = stack_b->elements[i + 1];
		i++;
	}
	stack_b->elements[i] = tmp;
	ft_printf("rrb\n");
	return (0);
}
