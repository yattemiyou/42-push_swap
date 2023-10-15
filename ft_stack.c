/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:23:41 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/15 13:46:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

#include "libft.h"

t_stack	ft_stack_initialize(char label, uint32_t capacity)
{
	t_stack	stack;

	stack.label = label;
	stack.buffer = ft_calloc(capacity, sizeof(int64_t));
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
