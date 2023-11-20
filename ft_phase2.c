/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:46:55 by anonymous         #+#    #+#             */
/*   Updated: 2023/11/18 19:28:54 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_phase2.h"

#include "ft_operation.h"
#include "ft_optimizer.h"
#include "libft.h"

static uint32_t	get_insertable_index(t_stack *stack, int n)
{
	uint32_t	prev;
	uint32_t	i;

	if (n < stack->min || n > stack->max)
		return (ft_stack_find(stack, stack->min));
	prev = stack->len - 1;
	i = 0;
	while (stack->buffer[prev] > n || n > stack->buffer[i])
		prev = ++i - 1;
	return (i);
}

static t_operation	get_operation(t_stack *a, t_stack *b, uint32_t index_b)
{
	t_operation	o;
	uint32_t	index_a;

	ft_bzero(&o, sizeof(o));
	index_a = get_insertable_index(a, b->buffer[index_b]);
	if (index_a != 0)
	{
		o.ra = index_a;
		o.rra = a->len - index_a;
	}
	if (index_b != 0)
	{
		o.rb = index_b;
		o.rrb = b->len - index_b;
	}
	return (o);
}

void	ft_phase2(t_stack *a, t_stack *b)
{
	t_operation	min;
	uint32_t	index_b;
	t_operation	o;

	while (b->len > 0)
	{
		min.cost = INT32_MAX;
		index_b = 0;
		while (index_b < b->len)
		{
			o = get_operation(a, b, index_b);
			o = ft_optimize_operation(&o);
			if (min.cost > o.cost)
				min = o;
			index_b++;
		}
		ft_stack_batch(a, b, min);
		ft_stack_push(a, b, TRUE);
	}
}
