/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:18:58 by akostian          #+#    #+#             */
/*   Updated: 2024/09/13 15:32:17 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	strict_atoi(const char *str)
{
	const int	sign = -(*str == '-') + (*str != '-');
	long int	ret;
	char		number_found;

	number_found = 0;
	ret = 0;
	if (*str == '-')
		str++;
	if (!*str)
		return (-1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		if (*(str + 1) && !number_found && (*str == '0'))
			return (-1);
		number_found = 1;
		ret = 10 * ret + (*str - '0');
		if ((ret * sign < INT_MIN)
			|| (ret * sign > INT_MAX))
			return (-1);
		str++;
	}
	return (ret * sign);
}
