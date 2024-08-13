/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:42:20 by akostian          #+#    #+#             */
/*   Updated: 2024/08/13 10:46:02 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_closest_min(int nbr, t_stack *stack)
{
	int	i;
	int	closest_min_index;
	int	closest_min;

	closest_min_index = ft_arr_min_index(stack->elements, stack->length);
	closest_min = stack->elements[closest_min_index];
	if (nbr < closest_min)
		return (ft_arr_max_index(stack->elements, stack->length));
	i = 0;
	while (i < stack->length)
	{
		if ((stack->elements[i] < nbr)
			&& (stack->elements[i] > closest_min))
		{
			closest_min_index = i;
			closest_min = stack->elements[i];
		}
		i++;
	}
	return (closest_min_index);
}

int	find_closest_max(int nbr, t_stack *stack)
{
	int	i;
	int	closest_max_index;
	int	closest_max;

	closest_max_index = ft_arr_max_index(stack->elements, stack->length);
	closest_max = stack->elements[closest_max_index];
	if (nbr > closest_max)
		return (ft_arr_min_index(stack->elements, stack->length));
	i = 0;
	while (i < stack->length)
	{
		if ((stack->elements[i] > nbr)
			&& (stack->elements[i] < closest_max))
		{
			closest_max_index = i;
			closest_max = stack->elements[i];
		}
		i++;
	}
	return (closest_max_index);
}
