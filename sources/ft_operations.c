/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:14:30 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/13 17:46:52 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_operations(char *op, t_stacks *stacks)
{
	bool	valid;

	valid = false;
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss"))
		valid = ft_swap(&stacks->a);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss"))
		valid = ft_swap(&stacks->b);
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr"))
		valid = ft_rotate(&stacks->a);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr"))
		valid = ft_rotate(&stacks->b);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr"))
		valid = ft_reverse_rotate(&stacks->a);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		valid = ft_reverse_rotate(&stacks->b);
	if (!ft_strcmp(op, "pb"))
		valid = push(&stacks->b, &stacks->a);
	if (!ft_strcmp(op, "pa"))
		valid = push(&stacks->a, &stacks->b);
	return (valid);
}
