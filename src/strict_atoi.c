/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:18:58 by akostian          #+#    #+#             */
/*   Updated: 2024/09/02 08:23:22 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	strict_atoi(const char *str)
{
	const int	sign = -(*str == '-') + (*str != '-');
	long int	ret;

	ret = 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		if ((10 * ret + (*str - '0') < INT_MIN)
			|| 10 * ret + (*str - '0') > INT_MAX)
			return (-1);
		ret = 10 * ret + (*str - '0');
		str++;
	}
	return (ret * sign);
}
