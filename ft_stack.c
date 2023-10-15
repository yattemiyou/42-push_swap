/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:23:41 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/15 15:56:55 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

#include <stdlib.h>
#include "ft_util.h"
#include "libft.h"

static void	ft_stack_append(t_stack *stack, int n)
{
	stack->buffer[stack->len] = n;
	stack->len += 1;
	if (n < stack->min)
		stack->min = n;
	if (n > stack->max)
		stack->max = n;
}

t_stack	ft_stack_initialize(char label, uint32_t size, int argc, char *argv[])
{
	t_stack	stack;
	int64_t	n;
	int		i;

	stack.label = label;
	stack.buffer = ft_calloc(size, sizeof(int64_t));
	stack.len = 0;
	stack.min = INT64_MAX;
	stack.max = INT64_MIN;
	if (stack.buffer == NULL)
		return (stack);
	i = 0;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n == INT64_MIN || ft_stack_find(&stack, n) >= 0)
		{
			free(stack.buffer);
			stack.buffer = NULL;
			break ;
		}
		ft_stack_append(&stack, n);
		i++;
	}
	return (stack);
}

int64_t	ft_stack_find(t_stack *stack, int n)
{
	uint32_t	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->buffer[i] == n)
			return (i);
		i++;
	}
	return (-1);
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
