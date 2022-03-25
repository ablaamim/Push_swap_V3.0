/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:15:58 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/25 11:41:22 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*list;
	size_t	size;
	size_t	range;
	int		order;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
}	t_data;

#endif
