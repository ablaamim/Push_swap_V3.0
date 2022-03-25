/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_a_nutshell.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:22:05 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/25 12:12:04 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
	float	coef[2];
	int		pos;
	int		*tmp;
	int		operate;
	int		count;
	void	(*ft[2])(struct s_data *, int, int);
}	t_data;

/*
 * Initialize my data structure
 * It takes the argv parameters and initialize the t_data struct
*/

t_data	*ft_data_initializer(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof(t_data));
	if (!data)
		ft_end_program(data, 3);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc - 1 == 0x0)
		exit (EXIT_FAILURE);
	data = ft_data_initializer(argc, argv);
	return (EXIT_SUCCESS);
}
