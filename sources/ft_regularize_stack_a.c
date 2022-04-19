/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regulatize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:45:29 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/19 08:51:51 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_regularize_stack_a(t_stacks *stacks)
{
	int		min;
	int		i;
	t_node	*tmp;
	char	*op;

	i = 0;
	tmp = stacks->a.head;
	min = get_min_value(tmp);
	while (tmp->nbr != min)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < (stacks->a.size / 2))
		op = "ra";
	else
		op = "rra";
	while (stacks->a.head->nbr != min)
		call_operation(op, stacks);
}
