/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:46:55 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/19 06:43:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_phase1.h"

#include "ft_operation.h"
#include "ft_util.h"

static void	ft_sort(t_stack *stack)
{
	int64_t	n1;
	int64_t	n2;
	int64_t	n3;

	if (stack->len != 3)
		return ;
	n1 = stack->buffer[0];
	n2 = stack->buffer[1];
	n3 = stack->buffer[2];
	if (n1 < n3 && n3 < n2)
	{
		ft_stack_swap(stack, TRUE);
		ft_stack_rotate(stack, TRUE);
	}
	else if (n2 < n1 && n1 < n3)
		ft_stack_swap(stack, TRUE);
	else if (n2 < n3 && n3 < n1)
		ft_stack_rotate(stack, TRUE);
	else if (n3 < n1 && n1 < n2)
		ft_stack_rrotate(stack, TRUE);
	else if (n3 < n2 && n2 < n1)
	{
		ft_stack_swap(stack, TRUE);
		ft_stack_rrotate(stack, TRUE);
	}
}

void	ft_phase1(t_stack *a, t_stack *b, int64_t ref, int64_t limit)
{
	int64_t	n[3];

	while (!ft_stack_is_sorted(a) && a->len > 3)
	{
		n[0] = a->buffer[a->len - 1];
		n[1] = a->buffer[0];
		n[2] = a->buffer[1];
		if (b->len > 0 && n[0] < b->buffer[0] && b->buffer[0] < n[1])
		{
			if (b->buffer[0] < limit)
				ft_stack_push(a, b);
		}
		else if (n[0] < n[2] && n[2] < n[1] && n[1] < limit)
			ft_stack_swap(a, TRUE);
		else if (n[0] < n[1] && n[1] < limit)
			ft_stack_rotate(a, TRUE);
		else if (n[0] == a->max && n[1] == a->min)
		{
			limit = ref;
			ft_stack_rotate(a, TRUE);
		}
		else
			ft_stack_push(b, a);
	}
	ft_sort(a);
}
