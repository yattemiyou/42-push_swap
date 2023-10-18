/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:46:55 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/18 20:01:37 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_phase3.h"

#include <stddef.h>
#include "ft_operation.h"
#include "libft.h"

void	ft_phase3(t_stack *stack)
{
	int64_t		index;
	t_operation	operation;

	index = ft_stack_find(stack, stack->min);
	ft_bzero(&operation, sizeof(operation));
	if (index <= stack->len / 2)
		operation.ra = index;
	else
		operation.rra = stack->len - index;
	ft_stack_batch(stack, NULL, operation);
}
