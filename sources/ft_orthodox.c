/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orthodox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:23:42 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/13 17:42:29 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
