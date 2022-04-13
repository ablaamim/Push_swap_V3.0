/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:21:21 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/12 16:28:53 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_value(t_node *tmp)
{
	int	max;

	max = MIN_INT;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min_value(t_node *tmp)
{
	int	min;

	min = MAX_INT;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

int	min_value(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

void	push_min_and_max_value_to_stack_b(t_stacks *stacks, int min, int max)
{
	t_node	*head;
	t_node	*last;
	size_t	size;
	size_t	i;

	i = 0;
	size = stacks->a.size;
	while (i < size)
	{
		head = stacks->a.head;
		last = ft_nodelast(stacks->a.head);
		if (head->nbr == min || head->nbr == max)
			call_operation("pb", stacks);
		else if (last->nbr == min || last->nbr == max)
		{
			call_operation("rra", stacks);
			call_operation("pb", stacks);
		}
		else
			call_operation("ra", stacks);
		i++;
	}
}
