/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:22:35 by akostian          #+#    #+#             */
/*   Updated: 2024/07/30 15:04:27 by akostian         ###   ########.fr       */
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

int	is_in_array(int nbr, int *array, int array_length);
int	parse_argv(t_stack *stack_a, t_stack *stack_b, char *argv);

#endif