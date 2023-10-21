/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:37:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/10/21 10:01:56 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optimizer.h"

#include "libft.h"

static t_operation	ra_rb(const t_operation *o)
{
	t_operation	operation;

	ft_bzero(&operation, sizeof(operation));
	if (o->ra > o->rb)
	{
		operation.ra = o->ra - o->rb;
		operation.rr = o->rb;
		operation.cost = o->ra;
	}
	else
	{
		operation.rb = o->rb - o->ra;
		operation.rr = o->ra;
		operation.cost = o->rb;
	}
	return (operation);
}

static t_operation	ra_rrb(const t_operation *o)
{
	t_operation	operation;

	ft_bzero(&operation, sizeof(operation));
	operation.ra = o->ra;
	operation.rrb = o->rrb;
	operation.cost = o->ra + o->rrb;
	return (operation);
}

static t_operation	rra_rb(const t_operation *o)
{
	t_operation	operation;

	ft_bzero(&operation, sizeof(operation));
	operation.rra = o->rra;
	operation.rb = o->rb;
	operation.cost = o->rra + o->rb;
	return (operation);
}

static t_operation	rra_rrb(const t_operation *o)
{
	t_operation	operation;

	ft_bzero(&operation, sizeof(operation));
	if (o->rra > o->rrb)
	{
		operation.rra = o->rra - o->rrb;
		operation.rrr = o->rrb;
		operation.cost = o->rra;
	}
	else
	{
		operation.rrb = o->rrb - o->rra;
		operation.rrr = o->rra;
		operation.cost = o->rrb;
	}
	return (operation);
}

t_operation	ft_optimize_operation(const t_operation *o)
{
	t_operation	pattern[4];
	uint32_t	min;
	uint32_t	i;

	pattern[0] = ra_rb(o);
	pattern[1] = ra_rrb(o);
	pattern[2] = rra_rb(o);
	pattern[3] = rra_rrb(o);
	min = 0;
	i = 1;
	while (i < 4)
	{
		if (pattern[min].cost > pattern[i].cost)
			min = i;
		i++;
	}
	return (pattern[min]);
}
