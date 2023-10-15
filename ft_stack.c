/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:23:41 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/15 11:31:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	ft_stack_initialize(char label)
{
	t_stack	stack;

	stack.label = label;
	stack.buffer = 0;
	stack.len = 0;
	stack.min = INT64_MAX;
	stack.max = INT64_MIN;
	return (stack);
}

void	ft_stack_push(t_stack *stack, int n)
{
	(void)stack;
	(void)n;
}

int64_t	ft_stack_pop(t_stack *stack)
{
	return (stack->buffer[0]);
}
