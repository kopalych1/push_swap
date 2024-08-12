/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:03:45 by akostian          #+#    #+#             */
/*   Updated: 2024/08/06 07:57:34 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_in_array(int nbr, int *array, size_t array_length)
{
	size_t	i;

	i = 0;
	while (i < array_length)
		if (nbr == array[i++])
			return (1);
	return (0);
}

void	*arr_dup(const void *src, size_t size_of_el, size_t size)
{
	void	*dst;

	dst = malloc(size_of_el * size);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, size_of_el * size);
	return (dst);
}

int	ft_max(const int val1, const int val2)
{
	if (val1 > val2)
		return (val1);
	return (val2);
}

int	ft_min(const int val1, const int val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}
