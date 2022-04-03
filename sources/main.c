/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:28:28 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/03 15:19:43 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**splited_args;

	splited_args = ft_args_unified(argc, argv);
	ft_arguments_validator(argc, splited_args);
	return (EXIT_SUCCESS);
}
