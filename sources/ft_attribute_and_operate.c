/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_and_operate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:40:55 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/19 08:42:13 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_attribute_operations(t_actions *def)
{
	if (!(def->a.top ^ def->b.top))
	{
		def->n_op_same = min_value(def->a.n_op, def->b.n_op);
		def->b.n_op -= def->n_op_same;
		def->a.n_op -= def->n_op_same;
	}
	if (def->a.top == true)
	{
		ft_memmove((char *)&def->a.op, "ra", 4);
		ft_memmove((char *)&def->op_same, "rr", 4);
	}
	else
	{
		ft_memmove((char *)&def->a.op, "rra", 4);
		ft_memmove((char *)&def->op_same, "rrr", 4);
	}
	if (def->b.top == true)
		ft_memmove((char *)&def->b.op, "rb", 4);
	else
		ft_memmove((char *)&def->b.op, "rrb", 4);
}

void	ft_operate_actions(t_stacks *stacks, t_actions *def)
{
	while (def->n_op_same--)
		call_operation(def->op_same, stacks);
	while (def->a.n_op--)
		call_operation(def->a.op, stacks);
	while (def->b.n_op--)
		call_operation(def->b.op, stacks);
	call_operation("pa", stacks);
}
