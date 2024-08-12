/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:22:35 by akostian          #+#    #+#             */
/*   Updated: 2024/08/09 11:27:11 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_stack
{
	int		*elements;
	int		length;
}	t_stack;

typedef struct s_sorting_settings
{
	int	initial_length;
	int	elements_amount;
	int	*sorted;
	int	sorted_length;
	int	current_a_length;
	int	current_average;
}	t_sorting_settings;

// void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		find_max_index(t_stack *stack);
int		find_min_index(t_stack *stack);
int		*sort_stack(t_stack *stack);
int		count_average(int *arr, int size);
int		is_sorted(int *arr, size_t size);

int		parse_argv(t_stack *stack_a, t_stack *stack_b, char *argv);
int		sort_algorithm(
			t_stack *stack_a,
			t_stack *stack_b,
			float chunk_percentage);

/* LIBFT */
int		ft_max(const int val1, const int val2);
int		ft_min(const int val1, const int val2);
int		is_in_array(int nbr, int *array, size_t array_length);
void	*arr_dup(const void *src, size_t size_of_el, size_t size);
/*  */

/*  */
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);
int		ra(t_stack *stack_a);
int		rb(t_stack *stack_b);
int		rrb(t_stack *stack_b);
/*  */
#endif