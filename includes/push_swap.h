/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:58:32 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/06 20:29:06 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int		nbr;
	int		index;
	void	*next;
}	t_node;

typedef struct s_stack
{
	t_node	head;
	size_t	size;
}	t_stack;

typedef	struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

char	**ft_merge_arguments(int argc, char **argv);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1,char *s2);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	**ft_split(char *s, char c);

#endif
