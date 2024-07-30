/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:03:45 by akostian          #+#    #+#             */
/*   Updated: 2024/07/30 15:04:12 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_in_array(int nbr, int *array, int array_length)
{
	int	i;

	i = -1;
	while (++i < array_length)
		if (nbr == array[i])
			return (1);
	return (0);
}
