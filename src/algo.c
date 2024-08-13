/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 07:41:21 by akostian          #+#    #+#             */
/*   Updated: 2024/08/13 11:32:39 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	(*calculate_a_push_cost(
							t_stack *stack_a,
							t_stack *stack_b,
							int *min_index
))[2]
{
	int	i;
	int	least_moves;
	int	moves;
	int	(*push_cost)[2];

	push_cost = malloc((sizeof(int) * 2) * stack_a->length);
	if (!push_cost)
		return (NULL);
	least_moves = INT_MAX;
	i = -1;
	while (++i < stack_a->length)
	{
		calculate_a_cost(stack_a, stack_b, i, push_cost);
		if ((push_cost[i][0] < 0 && push_cost[i][1] < 0)
			|| (push_cost[i][0] > 0 && push_cost[i][1] > 0))
			moves = ft_max(ft_abs(push_cost[i][0]), ft_abs(push_cost[i][1]));
		else
			moves = ft_abs(push_cost[i][0]) + ft_abs(push_cost[i][1]);
		if (moves < least_moves)
		{
			least_moves = moves;
			*min_index = i;
		}
	}
	return (push_cost);
}

int	(*calculate_b_push_cost(
							t_stack *stack_a,
							t_stack *stack_b,
							int *min_index
))[2]
{
	int	i;
	int	moves;
	int	least_moves;
	int	(*push_cost)[2];

	push_cost = malloc((sizeof(int) * 2) * stack_b->length);
	if (!push_cost)
		return (NULL);
	least_moves = INT_MAX;
	i = -1;
	while (++i < stack_b->length)
	{
		calculate_b_cost(stack_a, stack_b, i, push_cost);
		if ((push_cost[i][0] < 0 && push_cost[i][1] < 0)
			|| (push_cost[i][0] > 0 && push_cost[i][1] > 0))
			moves = ft_max(ft_abs(push_cost[i][0]), ft_abs(push_cost[i][1]));
		else
			moves = ft_abs(push_cost[i][0]) + ft_abs(push_cost[i][1]);
		if (moves < least_moves)
		{
			least_moves = moves;
			*min_index = i;
		}
	}
	return (push_cost);
}

void	stage_one(
				t_stack *stack_a,
				t_stack *stack_b
)
{
	int		(*push_cost)[2];
	int		min_index;

	while (stack_a->length > 3)
	{
		if (stack_b->length < 2)
		{
			pb(stack_a, stack_b, 1);
			continue ;
		}
		push_cost = calculate_a_push_cost(stack_a, stack_b, &min_index);
		rotate_stacks(stack_a, stack_b, push_cost[min_index]);
		pb(stack_a, stack_b, 1);
		free(push_cost);
	}
}

void	stage_two(t_stack *stack_a, t_stack *stack_b)
{
	int		min_index;
	int		max_index;
	int		(*push_cost)[2];

	while (stack_b->length)
	{
		push_cost = calculate_b_push_cost(stack_a, stack_b, &min_index);
		rotate_stacks(stack_a, stack_b, push_cost[min_index]);
		pa(stack_a, stack_b, 1);
		free(push_cost);
	}
	max_index = ft_arr_max_index(stack_a->elements, stack_a->length);
	while (max_index)
	{
		if (max_index < (stack_a->length / 2))
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
		max_index = ft_arr_max_index(stack_a->elements, stack_a->length);
	}
}

int	sort_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	stage_one(stack_a, stack_b);
	sort_three(stack_a);
	stage_two(stack_a, stack_b);
	return (0);
}

/* 
	// int i = 0;
	// while (i < stack_a->length)
	// {
	// 	ft_printf("|%d|:\t\t{%d} |%d|   \t\t(%d) (%d + %d)\n",
	// 		stack_a->elements[stack_a->length - 1 - i],
	//		find_closest_min(stack_a->elements[stack_a->length - 1 - i],
				stack_b),
	// 		stack_b->elements[find_closest_min
				stack_a->elements[stack_a->length - 1 - i], stack_b)],
	// 		ft_abs(push_cost[stack_a->length - 1 - i][0])
				+ ft_abs(push_cost[stack_a->length - 1 - i][1]),
	// 		push_cost[stack_a->length - 1 - i][0],
	// 		push_cost[stack_a->length - 1 - i][1]
	// 		);
	// 	i++;
	// }
	// ft_printf("min_index: %d\n", min_index);
 */