/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orthodox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:23:42 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/13 18:43:22 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_push_swap(t_stacks *stacks)
{
	ft_clear_stacks(stacks);
	exit (EXIT_FAILURE);
}

void	push_to_stack_a(t_stacks *stacks)
{
	t_actions	*def;
	def = NULL;
	def = ft_calloc(1, sizeof(t_actions));
	if (!def)
		exit_push_swap(stacks);
	while (stacks->b.head != NULL)
	{
		optimize_actions(stacks, def);
	}
	free(def);
}

void	push_to_stack_b(t_stacks *stacks)
{
	int	init_size;

	init_size = stacks->a.size;
	while (init_size)
	{
		if ((t_stacks *)(stacks->a.head)->keep_a)
			call_operation("ra", stacks);
		else
			call_operation("pb", stacks);
		init_size--;
	}
}
