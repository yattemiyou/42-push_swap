/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:25:07 by anonymous         #+#    #+#             */
/*   Updated: 2023/11/18 19:27:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATION_H
# define FT_OPERATION_H

# include "ft_stack.h"

typedef struct s_operation
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	cost;
}	t_operation;

void	ft_stack_batch(t_stack *a, t_stack *b, t_operation operation);
void	ft_stack_push(t_stack *dest, t_stack *src, int display);
void	ft_stack_rotate(t_stack *stack, int display);
void	ft_stack_rrotate(t_stack *stack, int display);
void	ft_stack_swap(t_stack *stack, int display);

#endif
