/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:49:41 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/19 14:14:05 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	nodes_to_keep_a(t_stack *a, int markup_head, bool def)
{
	int		num_keep_a;
	int		value_to_cmp;
	t_node	*tmp;

	num_keep_a = 0x0;
	tmp = a->head;
	while (tmp->nbr != markup_head)
		tmp = tmp->next;
	value_to_cmp = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr > value_to_cmp)
		{
			if (def == true)
				tmp->keep_a = true;
			num_keep_a++;
			value_to_cmp = tmp->nbr;
		}
		tmp = tmp->next;
	}
	return (num_keep_a);
}

void	ft_find_markup(t_stack *a)
{
	t_node	*tmp;
	int		num_keep_a;
	int		tmp_keep_a;

	num_keep_a = 0x0;
	tmp_keep_a = 0x0;
	tmp = a->head;
	while (tmp)
	{
		tmp_keep_a = nodes_to_keep_a(a, tmp->nbr, false);
		if (tmp_keep_a > num_keep_a)
		{
			a->markup_head = tmp->nbr;
			num_keep_a = tmp_keep_a;
		}
		tmp = tmp->next;
	}
}

void	ft_markup_elements(t_stack *a)
{
	int	num_keep_a;

	ft_find_markup(a);
	num_keep_a = nodes_to_keep_a(a, a->markup_head, true);
}
