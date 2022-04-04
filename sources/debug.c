/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:30:25 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/04 17:39:57 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stacks stacks)
{
	int	i;

	i = 0;
	ft_printf("\nsize:\t%d\t%d\n-----\nstack:", stacks.a.size, stacks.b.size);
	while (i < stacks.a.size || i < stacks.b.size)
	{
		if (i < stacks.a.size)
		{
			ft_printf("\t%d", stacks.a.head->nbr);
			if (stacks.a.head->next)
				stacks.a.head = stacks.a.head->next;
		}
		else
			ft_printf("\t");
		if (i < stacks.b.size)
		{
			ft_printf("\t%d", stacks.b.head->nbr);
			if (stacks.b.head->next)
				stacks.b.head = stacks.b.head->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\t_\t_\n\ta\tb\n> ");
}
