/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:46:55 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/17 23:03:24 by anonymous        ###   ########.fr       */
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
	(void)a;
	(void)b;
	ft_sort(a);
}
