/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 06:52:18 by akostian          #+#    #+#             */
/*   Updated: 2024/08/09 11:30:15 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max;

	i = -1;
	if (stack->length < 1)
		return (-1);
	max = stack->elements[0];
	while (++i < stack->length)
		if (stack->elements[i] > max)
			max = stack->elements[i];
	i = -1;
	while (++i < stack->length)
		if (stack->elements[i] == max)
			break ;
	return (i);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min;

	if (stack->length < 1)
		return (-1);
	min = stack->elements[0];
	i = -1;
	while (++i < stack->length)
		if (stack->elements[i] < min)
			min = stack->elements[i];
	i = -1;
	while (++i < stack->length)
		if (stack->elements[i] == min)
			break ;
	return (i);
}

int	*sort_stack(t_stack *stack)
{
	int	*stack_cpy;
	int	i;
	int	j;
	int	tmp;

	stack_cpy = arr_dup(stack->elements, sizeof(int), stack->length);
	if (!stack_cpy)
		return (NULL);
	i = -1;
	while (++i < stack->length)
	{
		j = i;
		while (++j < stack->length)
		{
			if (stack_cpy[i] > stack_cpy[j])
			{
				tmp = stack_cpy[i];
				stack_cpy[i] = stack_cpy[j];
				stack_cpy[j] = tmp;
			}
		}
	}
	return (stack_cpy);
}

int	count_average(int *arr, int size)
{
	int			i;
	long long	sum;

	sum = 0;
	i = 0;
	while (i < size)
		sum += arr[i++];
	return (sum / size);
}

int	is_sorted(int *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/* 

#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define RESET "\e[0m"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	a_max_index;
	int	b_max_index;
	int	a_min_index;
	int	b_min_index;

	a_max_index = find_max_index(stack_a);
	b_max_index = find_max_index(stack_b);
	a_min_index = find_min_index(stack_a);
	b_min_index = find_min_index(stack_b);
	i = ft_max(stack_a->length, stack_b->length) - 1;
	while (i >= 0)
	{
		ft_printf("|");
		
		if (i == a_max_index)
			ft_printf(RED);
		else if (i == a_min_index)
			ft_printf(GREEN);
		
		if (i >= 0 && i < stack_a->length)
			ft_printf("%d", stack_a->elements[i]);
		
		if (i == a_max_index || i == a_min_index)
			ft_printf(RESET);


		ft_printf("|\t|");


		if (i == b_max_index)
			ft_printf(RED);
		else if (i == b_min_index)
			ft_printf(GREEN);

		if (i >= 0 && i < stack_b->length)
			ft_printf("%d", stack_b->elements[i]);

		if (i == b_max_index || i == b_min_index)
			ft_printf(RESET);


		ft_printf("|\n");
		i--;
	}
	ft_printf("----\t----\n", stack_a->length);
	ft_printf("{%d}\t{%d}\n", stack_a->length, stack_b->length);
}
 */