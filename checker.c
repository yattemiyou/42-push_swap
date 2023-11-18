/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:03:26 by anonymous         #+#    #+#             */
/*   Updated: 2023/11/18 19:19:42 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_operation.h"
#include "ft_stack.h"
#include "libft.h"
#include "get_next_line.h"

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

static void	push_swap(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	size_t	len;

	len = ft_strlen(operation);
	if (ft_strncmp(operation, "sa", len) == 0)
		ft_stack_swap(stack_a, FALSE);
	else if (ft_strncmp(operation, "sb", len) == 0)
		ft_stack_swap(stack_b, FALSE);
	else if (ft_strncmp(operation, "ss", len) == 0)
	{
		ft_stack_swap(stack_a, FALSE);
		ft_stack_swap(stack_b, FALSE);
	}
	else if (ft_strncmp(operation, "pa", len) == 0)
		ft_stack_push(stack_a, stack_b);
	else if (ft_strncmp(operation, "pb", len) == 0)
		ft_stack_push(stack_b, stack_a);
}

static void	rotate(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	size_t	len;

	len = ft_strlen(operation);
	if (ft_strncmp(operation, "ra", len) == 0)
		ft_stack_rotate(stack_a, FALSE);
	else if (ft_strncmp(operation, "rb", len) == 0)
		ft_stack_rotate(stack_b, FALSE);
	else if (ft_strncmp(operation, "rr", len) == 0)
	{
		ft_stack_rotate(stack_a, FALSE);
		ft_stack_rotate(stack_b, FALSE);
	}
	else if (ft_strncmp(operation, "rra", len) == 0)
		ft_stack_rrotate(stack_a, FALSE);
	else if (ft_strncmp(operation, "rrb", len) == 0)
		ft_stack_rrotate(stack_b, FALSE);
	else if (ft_strncmp(operation, "rrr", len) == 0)
	{
		ft_stack_rrotate(stack_a, FALSE);
		ft_stack_rrotate(stack_b, FALSE);
	}
}

static int	run(t_stack *stack_a, t_stack *stack_b)
{
	char	*operation;

	operation = get_next_line(STDIN_FILENO);
	while (operation != NULL)
	{
		operation[ft_strlen(operation) - 1] = '\0';
		if (operation[0] == 'p' || operation[0] == 's')
			push_swap(operation, stack_a, stack_b);
		else if (operation[0] == 'r')
			rotate(operation, stack_a, stack_b);
		else
		{
			free(operation);
			return (FALSE);
		}
		free(operation);
		operation = get_next_line(STDIN_FILENO);
	}
	return (TRUE);
}

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
	if (run(&stack_a, &stack_b) == FALSE)
		ft_putendl_fd("Error", STDOUT_FILENO);
	else if (stack_a.len != (uint32_t)argc - 1 || stack_b.len != 0)
		ft_putendl_fd("KO", STDOUT_FILENO);
	else if (stack_a.buffer[0] != stack_a.min)
		ft_putendl_fd("KO", STDOUT_FILENO);
	else if (ft_stack_is_sorted(&stack_a) == FALSE)
		ft_putendl_fd("KO", STDOUT_FILENO);
	else
		ft_putendl_fd("OK", STDOUT_FILENO);
	free(stack_a.buffer);
	free(stack_b.buffer);
	return (0);
}
