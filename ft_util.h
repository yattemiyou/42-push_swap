/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:46:06 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/17 22:25:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <stdint.h>

# define TRUE 1
# define FALSE 0

int64_t	ft_atoi(const char *nptr);
void	print_operation(char *operation, char label);

#endif
