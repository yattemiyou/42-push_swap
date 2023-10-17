/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:27:59 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/17 19:55:51 by anonymous        ###   ########.fr       */
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

void	ft_stack_swap(t_stack *stack)
{
	int64_t	temp;

	temp = stack->buffer[0];
	stack->buffer[0] = stack->buffer[1];
	stack->buffer[1] = temp;
}
