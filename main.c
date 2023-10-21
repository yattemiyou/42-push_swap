/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:03:26 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/21 11:03:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_phase1.h"
#include "ft_phase2.h"
#include "ft_phase3.h"
#include "ft_stack.h"
#include "ft_util.h"
#include "libft.h"

static int	initialize(t_stack *a, t_stack *b, int argc, char *argv[])
{
	*a = ft_stack_initialize('a', argc - 1, argc - 1, &(argv[1]));
	if (a->buffer == NULL)
		return (FALSE);
	*b = ft_stack_initialize('b', argc - 1, 0, NULL);
	if (b->buffer == NULL)
	{
		free(a->buffer);
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int64_t	ref;
	int64_t	limit;

	if (argc <= 1)
		return (0);
	if (initialize(&stack_a, &stack_b, argc, argv) == FALSE)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	ref = stack_a.buffer[stack_a.len - 1];
	limit = INT64_MAX;
	ft_phase1(&stack_a, &stack_b, ref, limit);
	ft_phase2(&stack_a, &stack_b);
	ft_phase3(&stack_a);
	free(stack_a.buffer);
	free(stack_b.buffer);
	return (0);
}
