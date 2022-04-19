/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:37:09 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/19 09:04:37 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_number_op_stack(t_infos *info)
{
	if (info->ind < (info->size / 2))
	{
		info->top = true;
		info->n_op = info->ind;
	}
	else
	{
		info->top = false;
		info->n_op = info->size - info->ind;
	}
}

void	get_total_of_operations(t_actions *tmp, t_actions *def)
{
	tmp->total = tmp->a.n_op + tmp->b.n_op;
	if (!(tmp->a.top ^ tmp->b.top))
		tmp->total -= min_value(tmp->a.n_op, tmp->b.n_op);
	if (tmp->total < def->total)
		ft_memmove(def, tmp, sizeof(t_actions));
}

void	actions_in_stack_a(t_actions *tmp, t_actions *def, t_stacks *stacks,
		int value)
{
	t_node	*head;
	t_node	*previous;
	int		max;

	tmp->a.ind = 0;
	head = stacks->a.head;
	previous = ft_nodelast(head);
	max = get_max_value(head);
	while (head)
	{
		if ((head->nbr > value && previous->nbr < value)
			|| (head->nbr > value && previous->nbr == max)
			|| (head->nbr < value && (previous->nbr == max && value > max)))
			break ;
		previous = head;
		head = head->next;
		(tmp->a.ind)++;
	}
	calculate_number_op_stack(&tmp->a);
	get_total_of_operations(tmp, def);
}

void	ft_optimize_actions_to_push_to_a(t_stacks *stacks, t_actions *def)
{
	t_actions	tmp;
	t_node		*tmp_b;

	ft_bzero(&tmp, sizeof(t_actions));
	tmp.a.size = stacks->a.size;
	tmp.b.size = stacks->b.size;
	def->total = MAX_INT;
	tmp_b = stacks->b.head;
	while (tmp_b)
	{
		calculate_number_op_stack(&tmp.b);
		actions_in_stack_a(&tmp, def, stacks, tmp_b->nbr);
		tmp_b = tmp_b->next;
		tmp.b.ind++;
	}
}
