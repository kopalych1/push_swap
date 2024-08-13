/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:37:47 by akostian          #+#    #+#             */
/*   Updated: 2024/08/13 11:12:58 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	calculate_a_cost(
						t_stack *stack_a,
						t_stack *stack_b,
						int i, int (*push_cost)[2])
{
	int			closest_min_index;

	closest_min_index = find_closest_min(stack_a->elements[i], stack_b);
	if (i < stack_a->length / 2)
		push_cost[i][0] = -ft_min(i + 1, stack_a->length - 1 - i);
	else
		push_cost[i][0] = ft_min(i + 1, stack_a->length - 1 - i);
	if (closest_min_index < stack_a->length / 2)
		push_cost[i][1] = -ft_min(closest_min_index + 1,
				stack_b->length - 1 - closest_min_index);
	else
		push_cost[i][1] = ft_min(closest_min_index + 1,
				stack_b->length - 1 - closest_min_index);
}

void	calculate_b_cost(
						t_stack *stack_a,
						t_stack *stack_b,
						int i, int (*push_cost)[2])
{
	int			closest_max_index;

	closest_max_index = find_closest_max(stack_b->elements[i], stack_a);
	if (i < stack_b->length / 2)
		push_cost[i][1] = -ft_min(i + 1, stack_b->length - 1 - i);
	else
		push_cost[i][1] = ft_min(i + 1, stack_b->length - 1 - i);
	if (closest_max_index < stack_a->length / 2)
		push_cost[i][0] = -ft_min(closest_max_index + 1,
				stack_a->length - 1 - closest_max_index);
	else
		push_cost[i][0] = ft_min(closest_max_index + 1,
				stack_a->length - 1 - closest_max_index);
}
