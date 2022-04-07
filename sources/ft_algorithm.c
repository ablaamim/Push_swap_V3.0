/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:18:01 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/07 21:19:03 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	sorted_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->head)
		return (false);
	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->nbr > ((t_node *)(tmp->next))->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static bool	empty_stack(t_stack *stack)
{
	if (stack->size == 0 && !stack->head)
		return (true);
	return (false);
}

bool	ft_sorted(t_stacks *stacks)
{
	if (sorted_stack(&stacks->a) || empty_stack(&stacks->b))
		return (true);
	return (false);
}

void	ft_algorithm(t_stacks *stacks)
{
	if (ft_sorted(stacks))
		return ;
}
