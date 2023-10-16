/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:25:07 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/17 06:35:22 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATION_H
# define FT_OPERATION_H

# include "ft_stack.h"

void	ft_stack_rotate(t_stack *stack);
void	ft_stack_rrotate(t_stack *stack);
int		ft_stack_is_sorted(t_stack *stack);

#endif
