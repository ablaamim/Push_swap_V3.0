/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:19:33 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/11 17:26:19 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_reverse_rotate(t_stack *stack)
{
	t_node	*to_move;

	if (stack->size < 2 || !stack->head)
		return (true);
	to_move = stack->head;
	while (((t_node *)(to_move->next))->next)
		to_move = to_move->next;
	((t_node *)(to_move->next))->next = stack->head;
	stack->head = to_move->next;
	to_move->next = NULL;
	return (true);
}
