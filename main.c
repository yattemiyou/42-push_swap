/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:03:26 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/16 06:31:18 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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

// #include <stdio.h>
// void	print_stack(t_stack *stack)
// {
// 	uint32_t	i;

// 	printf("stack_%c\n", stack->label);

// 	i = 0;
// 	while (i < stack->len)
// 	{
// 		printf("%ld ", stack->buffer[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc <= 1)
		return (0);
	if (initialize(&stack_a, &stack_b, argc, argv) == FALSE)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	free(stack_a.buffer);
	free(stack_b.buffer);
	return (0);
}
