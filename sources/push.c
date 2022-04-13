/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:40:12 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/13 17:40:41 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	push(t_stack *to, t_stack *from)
{
	t_node	*to_move;

	if (from->size < 1 || !from->head)
		return (true);
	to_move = from->head;
	from->head = from->head->next;
	to_move->next = NULL;
	ft_nodeadd_front(&to->head, to_move);
	to->size++;
	from->size--;
	return (true);
}
