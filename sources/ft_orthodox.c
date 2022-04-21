/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orthodox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:23:42 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/19 20:08:36 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_push_swap(t_stacks *stacks)
{
	ft_clear_stacks(stacks);
	exit (EXIT_FAILURE);
}

void	ft_steps_debuger(t_actions	*def)
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("		t_infos :  \n");
	ft_printf("TOP A					 : %d\n", def->a.top);
	ft_printf("TOP B					 : %d\n", def->b.top);
	ft_printf("INDEX A				 	 : %d\n", def->a.ind);
	ft_printf("INDEX B					 : %d\n", def->b.ind);
	ft_printf("SIZE A					 : %d\n", def->a.size);
	ft_printf("SIZE B					 : %d\n", def->b.size);
	ft_printf("N_OP A					 : %d\n", def->a.n_op);
	ft_printf("N_OP B					 : %d\n", def->b.n_op);
	ft_printf("TOTAL					 : %d\n", def->total);
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("		t_actions\n");
	ft_printf("OPERATION A				 : %s\n", def->a.op);
	ft_printf("OPERATION B 				 : %s\n", def->b.op);
	ft_printf("SAME OPERATIONS				 : %s\n", def->op_same);
	ft_printf("NUMBER OF SAME OPERATIONS		 : %d\n", def->n_op_same);
	ft_printf("-----------------------------------------------------------\n");
}

void	push_to_stack_a(t_stacks *stacks)
{
	t_actions	*def;

	def = NULL;
	def = ft_calloc(1, sizeof(t_actions));
	if (!def)
		exit_push_swap(stacks);
	while (stacks->b.head != NULL)
	{
		ft_optimize_actions_to_push_to_a(stacks, def);
		ft_attribute_operations(def);
		ft_operate_actions(stacks, def);
		ft_bzero(def, sizeof(t_actions));
	}
	free(def);
}

void	push_to_stack_b(t_stacks *stacks)
{
	int	init_size;

	init_size = stacks->a.size;
	while (init_size)
	{
		if ((t_stacks *)(stacks->a.head)->keep_a)
			call_operation("ra", stacks);
		else
			call_operation("pb", stacks);
		init_size--;
	}
}
