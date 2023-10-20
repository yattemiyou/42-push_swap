/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:46:55 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/18 20:16:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_phase2.h"

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


void	ft_phase2(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}
