/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 07:41:21 by akostian          #+#    #+#             */
/*   Updated: 2024/08/29 01:09:30 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

double	calc_percentage(int x)
{
	if (x >= 1000)
		return (0.08);
	else if (x >= 500)
		return (0.12);
	else if (x >= 300)
		return (0.18);
	else if (x >= 100)
		return (0.23);
	else if (x <= 5)
		return (1);
	return (0.26);
}

void	push_b(
				t_stack *stack_a,
				t_stack *stack_b,
				t_sorting_settings *settings,
				int i
)
{
	int			current_len;
	int			current_el;
	int			j;

	current_len = stack_a->length;
	j = 0;
	while (j++ < current_len && stack_a->length)
	{
		current_el = stack_a->elements[stack_a->length - 1];
		if (is_in_array(
				current_el,
				&(settings->sorted[i * settings->elements_amount]),
				settings->sorted_length
			))
		{
			pb(stack_a, stack_b, 1);
			if (current_el >= settings->current_average)
				rb(stack_b, 1);
		}
		else
			ra(stack_a, 1);
	}
}

void	min_push_stage_one(
				t_stack *stack_a,
				t_stack *stack_b,
				t_sorting_settings *settings
)
{
	int			i;

	i = 0;
	while (stack_a->length)
	{
		settings->sorted_length = ft_min(settings->elements_amount,
				settings->initial_length - (i * settings->elements_amount));
		settings->current_a_length = stack_a->length;
		settings->current_average = count_average(
				&(settings->sorted[i * settings->elements_amount]),
				settings->sorted_length);
		push_b(stack_a, stack_b, settings, i);
		i++;
	}
}

void	min_push_stage_two(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;

	while (stack_b->length)
	{
		max_index = ft_arr_max_index(stack_b->elements, stack_b->length);
		while (max_index != stack_b->length - 1)
		{
			if ((max_index - (stack_b->length / 2)) < 0)
				rrb(stack_b, 1);
			else
				rb(stack_b, 1);
			max_index = ft_arr_max_index(stack_b->elements, stack_b->length);
		}
		pa(stack_a, stack_b, 1);
	}
}

int	algo_min_push(t_stack *stack_a, t_stack *stack_b)
{
	t_sorting_settings	settings;

	settings.initial_length = stack_a->length;
	settings.elements_amount
		= calc_percentage(stack_a->length) * stack_a->length;
	settings.sorted = sort_stack(stack_a);
	if (!settings.sorted)
		return (-1);
	min_push_stage_one(stack_a, stack_b, &settings);
	min_push_stage_two(stack_a, stack_b);
	free(settings.sorted);
	return (0);
}
