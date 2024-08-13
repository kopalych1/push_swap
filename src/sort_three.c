/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:12:38 by akostian          #+#    #+#             */
/*   Updated: 2024/08/13 11:12:47 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *stack_a)
{
	if (stack_a->elements[2] > stack_a->elements[0]
		&& stack_a->elements[2] > stack_a->elements[1])
		ra(stack_a, 1);
	else if (stack_a->elements[1] > stack_a->elements[0]
		&& stack_a->elements[1] > stack_a->elements[2])
		rra(stack_a, 1);
	if (stack_a->elements[1] < stack_a->elements[2])
		sa(stack_a, 1);
}
