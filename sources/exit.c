/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:00 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/04 20:32:31 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stack_free(t_node **lst, int size)
{
	t_node	*to_free;
	int		i;

	to_free = *lst;
	if (!lst || *lst)
		return ;
	i = 0x0;
	while (i < size)
	{
		*lst = to_free->next;
		free(to_free);
		to_free = *lst;
		i++;
	}
	*lst = NULL;
}

void	ft_clear_stacks(t_stacks *stacks)
{
	ft_stack_free(&stacks->a.head, stacks->a.size);
	ft_stack_free(&stacks->b.head, stacks->a.size);
}

void	exit_program(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	ft_clear_stacks(stacks);
	exit(EXIT_FAILURE);
}
