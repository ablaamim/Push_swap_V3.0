/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:48 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/19 14:30:56 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	read_and_execute_commands(t_stacks *stacks, bool verbose)
{
	char	*op;
	int		ret;
	bool	valid_op;

	if (verbose)
		print_stacks(*stacks);
	while (true)
	{
		ret = get_next_line(0, &op);
		if (ret < 0)
			exit_program(stacks);
		if (!ret)
			break ;
		valid_op = ft_operations(op, stacks);
		free(op);
		if (!valid_op)
			exit_program(stacks);
		if (verbose)
		{
			ft_printf("------------------\nOP : %s\n------------------\n", op);
			print_stacks(*stacks);
		}
	}
	free(op);
}

static void	check_if_is_sorted(t_stacks *stacks)
{
	bool	sorted;

	sorted = ft_sorted(stacks);
	if (sorted)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**argv_split;
	bool		verbose;

	if (argc == 1)
		return (EXIT_FAILURE);
	verbose = !(ft_strcmp(argv[1], "-debug"));
	if (verbose)
		argv_split = ft_args_unified(--argc, &argv[1]);
	else
		argv_split = ft_args_unified(argc, argv);
	ft_arguments_validator(argc, argv_split);
	ft_stacks_constructor(argv_split, &stacks);
	ft_array_free((void **)argv_split);
	read_and_execute_commands(&stacks, verbose);
	check_if_is_sorted(&stacks);
	ft_clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}
