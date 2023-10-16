/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:27:59 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/17 06:44:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"

#include "ft_util.h"

void	ft_stack_rotate(t_stack *stack)
{
	int64_t	n;

	n = ft_stack_pop(stack, 0);
	ft_stack_insert(stack, stack->len, n);
}

void	ft_stack_rrotate(t_stack *stack)
{
	int64_t	n;

	n = ft_stack_pop(stack, stack->len - 1);
	ft_stack_insert(stack, 0, n);
}

int	ft_stack_is_sorted(t_stack *stack)
{
	uint32_t	index;
	uint32_t	i;
	int64_t		current;
	int64_t		next;

	if (stack->len <= 1)
		return (TRUE);
	index = ft_stack_find(stack, stack->min);
	i = index;
	while (i < index + stack->len - 1)
	{
		current = stack->buffer[i % stack->len];
		next = stack->buffer[(i + 1) % stack->len];
		if (current >= next)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
