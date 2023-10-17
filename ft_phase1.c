/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:46:55 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/18 06:54:41 by anonymous        ###   ########.fr       */
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

void	ft_phase1(t_stack *a, t_stack *b)
{
	int64_t ref = a->buffer[a->len - 1];
	int64_t limit = INT64_MAX;

	int64_t prev;
	int64_t cur;
	int64_t next;
	while (!ft_stack_is_sorted(a) && a->len > 3)
	{
		prev = a->buffer[a->len - 1];
		cur = a->buffer[0];
		next = a->buffer[1];
		
		if (b->len > 0 && prev < b->buffer[0] && b->buffer[0] < cur && b->buffer[0] < limit)
		{
			ft_stack_push(a, b);
			continue;
		}

		if (prev < next && next < cur && cur < limit)
		{
			ft_stack_swap(a, TRUE);
			continue;
		}

		if (prev < cur && cur < limit)
		{
			ft_stack_rotate(a, TRUE);
			continue;
		}

		if (prev == a->max && cur == a->min)
		{
			limit = ref;
			ft_stack_rotate(a, TRUE);
			continue;
		}

		ft_stack_push(b, a);
	}
	
	ft_sort(a);
}
