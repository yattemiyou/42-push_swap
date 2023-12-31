/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:23:41 by anonymous         #+#    #+#             */
/*   Updated: 2023/11/25 17:18:11 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

#include <stdlib.h>
#include "ft_util.h"
#include "libft.h"

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
		ft_stack_insert(&stack, stack.len, n);
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

void	ft_stack_insert(t_stack *stack, uint32_t index, int n)
{
	int64_t	*src;
	int64_t	*dest;

	src = &(stack->buffer[index]);
	dest = &(stack->buffer[index + 1]);
	ft_memmove(dest, src, (stack->len - index) * sizeof(int64_t));
	stack->len += 1;
	stack->buffer[index] = n;
	if (n < stack->min)
		stack->min = n;
	if (n > stack->max)
		stack->max = n;
}

int64_t	ft_stack_pop(t_stack *stack, uint32_t index)
{
	int64_t		*src;
	int64_t		*dest;
	int64_t		n;
	uint32_t	i;

	n = stack->buffer[index];
	src = &(stack->buffer[index + 1]);
	dest = &(stack->buffer[index]);
	ft_memmove(dest, src, (stack->len - index - 1) * sizeof(int64_t));
	stack->len -= 1;
	if (n == stack->min || n == stack->max)
	{
		stack->min = INT64_MAX;
		stack->max = INT64_MIN;
		i = 0;
		while (i < stack->len)
		{
			if (stack->buffer[i] < stack->min)
				stack->min = stack->buffer[i];
			if (stack->buffer[i] > stack->max)
				stack->max = stack->buffer[i];
			i++;
		}
	}
	return (n);
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
