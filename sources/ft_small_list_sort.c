/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_list_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:41:22 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/11 16:14:19 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	attribute_value(t_node *node, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = node->nbr;
		node = node->next;
		i++;
	}
}

void	call_operation(char *operation, t_stacks *stacks)
{
	ft_operations(operation, stacks);
	ft_printf("%s\n", operation);
}

void	ft_sort_list_of_two(t_stacks *stacks)
{
	int	numb[2];

	if (!stacks)
		return ;
	attribute_value(stacks->a.head, numb, 2);
	if (numb[0] > numb[1])
		call_operation("sa", stacks);
}
