/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:57:37 by akostian          #+#    #+#             */
/*   Updated: 2024/08/15 16:30:22 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_stacks(t_stack *stack_a, t_stack *stack_b, int length)
{
	stack_a->length = length;
	stack_b->length = 0;
	stack_a->elements = (int *)malloc(sizeof(int) * length);
	stack_b->elements = (int *)malloc(sizeof(int) * length);
	if (!stack_a->elements || !stack_b->elements)
		return (ft_printf("MALLOC ERROR\n"), 0);
	return (1);
}

int	is_all_numbers(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		if (!ft_atoi(arr[i]) && arr[i][0] != '0')
			return (0);
	return (1);
}

char	**get_values(int argc, char **argv, int *length)
{
	char	**splited;
	int		i;

	if (argc < 3)
	{
		splited = ft_split(argv[1], ' ');
		if (!splited)
			return (ft_printf("MALLOC ERROR\n"), NULL);
		i = 0;
		while (splited[i])
			i++;
		*length = i;
	}
	else
	{
		splited = &(argv[1]);
		*length = argc - 1;
	}
	if (!is_all_numbers(splited))
		return (ft_printf("ARGUMENTS ERROR\n"), NULL);
	return (splited);
}

void	free_arr(char **splited)
{
	size_t	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
}

int	parse_argv(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	char	**splited;
	int		i;
	int		length;

	splited = get_values(argc, argv, &length);
	if (!splited)
		return (-1);
	if (!init_stacks(stack_a, stack_b, length))
		return (-1);
	i = -1;
	while (++i < length)
	{
		if (is_in_array(ft_atoi(splited[length - i - 1]),
				stack_a->elements, i))
		{
			if (argc < 3)
				free_arr(splited);
			return (ft_printf("DUPLICATE ERROR\n"), -1);
		}
		stack_a->elements[i] = ft_atoi(splited[length - i - 1]);
	}
	if (argc < 3)
		free_arr(splited);
	return (1);
}
