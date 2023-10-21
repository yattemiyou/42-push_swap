/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:46:06 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/19 21:23:44 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <stdint.h>
# include "ft_stack.h"

# define TRUE 1
# define FALSE 0

int64_t	ft_atoi(const char *nptr);
void	print_operation(char *operation, char label);
void	print_stack(t_stack *stack);

#endif
