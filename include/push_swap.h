/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:22:35 by akostian          #+#    #+#             */
/*   Updated: 2024/09/02 04:20:01 by akostian         ###   ########.fr       */
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

void	sort_three(t_stack *stack_a);

/* SORT ALGO UTILS */
int		find_closest_min(int nbr, t_stack *stack);
int		find_closest_max(int nbr, t_stack *stack);
void	calculate_a_cost(
			t_stack *stack_a,
			t_stack *stack_b,
			int i, int (*push_cost)[2]
			);
void	calculate_b_cost(
			t_stack *stack_a,
			t_stack *stack_b,
			int i, int (*push_cost)[2]
			);
void	rotate_stacks(
			t_stack *stack_a,
			t_stack *stack_b,
			int push_cost[2]
			);

// void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		ft_arr_max_index(int *arr, size_t size);
int		ft_arr_min_index(int *arr, size_t size);
int		*sort_stack(t_stack *stack);
int		count_average(int *arr, int size);
int		is_sorted(int *arr, size_t size);

int		parse_argv(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
int		algo_turk(t_stack *stack_a, t_stack *stack_b);
int		algo_min_push(t_stack *stack_a, t_stack *stack_b);

/* UTILS */
int		strict_atoi(const char *str);
int		ft_max(const int val1, const int val2);
int		ft_min(const int val1, const int val2);
int		is_in_array(int nbr, int *array, size_t array_length);
int		ft_arr_min(int *arr, size_t size);
void	*arr_dup(const void *src, size_t size_of_el, size_t size);
/*  */

/*  */
int		sa(t_stack *stack_a, int do_print);
int		pa(t_stack *stack_a, t_stack *stack_b, int do_print);
int		pb(t_stack *stack_a, t_stack *stack_b, int do_print);
int		ra(t_stack *stack_a, int do_print);
int		rb(t_stack *stack_b, int do_print);
int		rr(t_stack *stack_a, t_stack *stack_b, int do_print);
int		rra(t_stack *stack_a, int do_print);
int		rrb(t_stack *stack_b, int do_print);
int		rrr(t_stack *stack_a, t_stack *stack_b, int do_print);
/*  */
#endif