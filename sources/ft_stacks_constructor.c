/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_constructor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:48:45 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/12 16:27:54 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_create_node(int numb)
{
	t_node	*elem;

	elem = ft_calloc(0x1, sizeof(t_node));
	if (!elem)
		return (0x0);
	elem->nbr = numb;
	elem->next = NULL;
	return (elem);
}

void	ft_nodeadd_back(t_node **lst, t_node *new_node)
{
	t_node	*tmp;

	tmp = *lst;
	if (!new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

t_node	*ft_nodelast(t_node *lst)
{
	t_node	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_nodeadd_front(t_node **lst, t_node *new_node)
{
	if (!new_node)
		return ;
	if (*lst)
		new_node->next = *lst;
	*lst = new_node;
}

void	ft_stacks_constructor(char	**argv, t_stacks *stacks)
{
	t_node	*new_node;

	stacks->a = (t_stack){0};
	stacks->b = (t_stack){0};
	while (argv[stacks->a.size])
	{
		new_node = ft_create_node(ft_atoi(argv[stacks->a.size]));
		if (!new_node)
			exit_program(stacks);
		ft_nodeadd_back(&stacks->a.head, new_node);
		(stacks->a.size)++;
	}
}
