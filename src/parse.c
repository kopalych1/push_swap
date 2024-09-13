/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:57:37 by akostian          #+#    #+#             */
/*   Updated: 2024/09/02 08:37:56 by akostian         ###   ########.fr       */
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
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	is_all_numbers(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (strict_atoi(arr[i]) == -1
			&& !(arr[i][0] == '-' && arr[i][1] == '1'))
			return (0);
	}
	return (1);
}

void	free_arr(char **splited, int do_free)
{
	size_t	i;

	if (!do_free)
		return ;
	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
}

char	**get_values(int argc, char **argv, int *length)
{
	char	**splited;
	int		i;

	if (argc < 3)
	{
		splited = ft_split(argv[1], ' ');
		if (!splited)
			return (write(2, "Error\n", 6), NULL);
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
	if (is_all_numbers(splited))
		return (splited);
	free_arr(splited, (argc < 3));
	return (write(2, "Error\n", 6), NULL);
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
		return (free_arr(splited, (argc < 3)), -1);
	i = -1;
	while (++i < length)
	{
		if (is_in_array(ft_atoi(splited[length - i - 1]),
				stack_a->elements, i))
		{
			free_arr(splited, (argc < 3));
			return (write(2, "Error\n", 6), -1);
		}
		stack_a->elements[i] = ft_atoi(splited[length - i - 1]);
	}
	free_arr(splited, (argc < 3));
	return (1);
}
