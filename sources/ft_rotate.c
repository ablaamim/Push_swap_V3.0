/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:13:37 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/11 17:19:15 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_rotate(t_stack *stack)
{
	t_node	*to_move;

	if (stack->size < 2 || !stack->head)
		return (true);
	to_move = stack->head;
	stack->head = stack->head->next;
	to_move->next = NULL;
	ft_nodeadd_back(&stack->head, to_move);
	return (true);
}
