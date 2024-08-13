/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:47:10 by akostian          #+#    #+#             */
/*   Updated: 2024/08/13 11:28:03 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_single(
						t_stack *stack,
						int *moves,
						int (*rotate)(t_stack *, int),
						int (*rev_rotate)(t_stack *, int)
)
{
	while (*moves)
	{
		if (*moves > 0)
		{
			rotate(stack, 1);
			(*moves)--;
		}
		else
		{
			rev_rotate(stack, 1);
			(*moves)++;
		}
	}
}

void	rotate_both(
					t_stack *stack_a,
					t_stack *stack_b,
					int *a_moves,
					int *b_moves
)
{
	while (*a_moves && *b_moves)
	{
		if (*a_moves > 0 && *b_moves > 0)
		{
			rr(stack_a, stack_b, 1);
			(*a_moves)--;
			(*b_moves)--;
		}
		else if (*a_moves < 0 && *b_moves < 0)
		{
			rrr(stack_a, stack_b, 1);
			(*a_moves)++;
			(*b_moves)++;
		}
		else
			break ;
	}
}

void	rotate_stacks(t_stack *stack_a, t_stack *stack_b, int push_cost[2])
{
	rotate_both(stack_a, stack_b, &push_cost[0], &push_cost[1]);
	rotate_single(stack_a, &push_cost[0], ra, rra);
	rotate_single(stack_b, &push_cost[1], rb, rrb);
}
