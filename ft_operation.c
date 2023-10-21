/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:27:59 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/17 22:32:19 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"

#include <unistd.h>
#include "ft_util.h"
#include "libft.h"

void	ft_stack_batch(t_stack *a, t_stack *b, t_operation operation)
{
	while (operation.ra-- > 0)
		ft_stack_rotate(a, TRUE);
	while (operation.rb-- > 0)
		ft_stack_rotate(b, TRUE);
	while (operation.rr-- > 0)
	{
		ft_putendl_fd("rr", STDOUT_FILENO);
		ft_stack_rotate(a, FALSE);
		ft_stack_rotate(b, FALSE);
	}
	while (operation.rra-- > 0)
		ft_stack_rrotate(a, TRUE);
	while (operation.rrb-- > 0)
		ft_stack_rrotate(b, TRUE);
	while (operation.rrr-- > 0)
	{
		ft_putendl_fd("rrr", STDOUT_FILENO);
		ft_stack_rrotate(a, FALSE);
		ft_stack_rrotate(b, FALSE);
	}
}

void	ft_stack_push(t_stack *dest, t_stack *src)
{
	print_operation("p", dest->label);
	ft_stack_insert(dest, 0, ft_stack_pop(src, 0));
}

void	ft_stack_rotate(t_stack *stack, int display)
{
	int64_t	n;

	print_operation("r", stack->label * display);
	n = ft_stack_pop(stack, 0);
	ft_stack_insert(stack, stack->len, n);
}

void	ft_stack_rrotate(t_stack *stack, int display)
{
	int64_t	n;

	print_operation("rr", stack->label * display);
	n = ft_stack_pop(stack, stack->len - 1);
	ft_stack_insert(stack, 0, n);
}

void	ft_stack_swap(t_stack *stack, int display)
{
	int64_t	temp;

	print_operation("s", stack->label * display);
	temp = stack->buffer[0];
	stack->buffer[0] = stack->buffer[1];
	stack->buffer[1] = temp;
}
