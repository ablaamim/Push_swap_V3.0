/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:18:59 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/11 16:34:49 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_swap(t_stack *stack)
{
	t_node	tmp;
	t_node	*node;
	t_node	*next_node;

	if (stack->size < 2 || !(stack->head) || !((t_node *)(stack->head)->next))
		return (true);
	node = stack->head;
	next_node = stack->head->next;
	tmp.index = node->index;
	tmp.nbr = node->nbr;
	tmp.keep_a = node->keep_a;
	node->index = next_node->index;
	node->nbr = next_node->nbr;
	node->keep_a = next_node->keep_a;
	next_node->index = tmp.index;
	next_node->nbr =  tmp.nbr;
	next_node->keep_a = tmp.keep_a;
	return (true);
}
