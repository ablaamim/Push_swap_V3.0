/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:28:28 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/13 17:59:26 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char		**splited_args;
	t_stacks	stacks;

	splited_args = ft_args_unified(argc, argv);
	ft_arguments_validator(argc, splited_args);
	ft_stacks_constructor(splited_args, &stacks);
	ft_array_free((void **) splited_args);
	print_stacks(stacks);
	ft_algorithm(&stacks);
	print_stacks(stacks);
	return (EXIT_SUCCESS);
}
