/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_a_nutshell.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:52:43 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/06 15:30:57 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// Linked list to implement a stack
typedef struct s_node
{
	int		number;
	int		index;
	void	*next;
}	t_node;

// Stack implementation
typedef struct s_stack
{
	t_node	*head;
	size_t	size;
}	t_stack;

// Both stacks a and b
typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

char	**ft_merge_argvalues(int argc, char **argv);

int	main(int argc, char **argv)
{
	char	**split_argvalues;

	split_argvalues = ft_merge_argvalues(argc, argv);
	return (EXIT_SUCCESS);
}
