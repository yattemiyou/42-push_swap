/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:46:36 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/17 22:25:44 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

#include <unistd.h>
#include "libft.h"

int64_t	ft_atoi(const char *nptr)
{
	int64_t	sign;
	int64_t	value;

	sign = 1;
	value = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		value = value * 10 + (*nptr - '0');
		if ((sign * value > INT32_MAX) || (sign * value < INT32_MIN))
			return (INT64_MIN);
		nptr++;
		if (*nptr == '\0')
			return (sign * value);
	}
	return (INT64_MIN);
}

void	print_operation(char *operation, char label)
{
	if (label == FALSE)
		return ;
	ft_putstr_fd(operation, STDOUT_FILENO);
	ft_putchar_fd(label, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}
