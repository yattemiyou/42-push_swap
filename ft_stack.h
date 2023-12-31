/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:16:18 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/17 19:55:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdint.h>

typedef struct s_stack
{
	char		label;
	int64_t		*buffer;
	uint32_t	len;
	int64_t		min;
	int64_t		max;
}	t_stack;

t_stack	ft_stack_initialize(char label, uint32_t size, int argc, char *argv[]);
int64_t	ft_stack_find(t_stack *stack, int n);
void	ft_stack_insert(t_stack *stack, uint32_t index, int n);
int64_t	ft_stack_pop(t_stack *stack, uint32_t index);
int		ft_stack_is_sorted(t_stack *stack);

#endif
