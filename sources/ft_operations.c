/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:14:30 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/11 16:17:14 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_operations(char *op, t_stacks *stacks)
{
	bool	valid;

	valid = false;
	if (!ft_strcmp(op, "sa"))
		valid = ft_swap(&stacks->a);
	return (valid);
}
