/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_unified.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:33:46 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/03 15:39:42 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_arguments_validator(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_array_free((void **) argv);
		exit(EXIT_SUCCESS);
	}
	if (!ft_parser(argv))
	{
		ft_array_free((void **) argv);
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}

char	**ft_args_unified(int argc, char **argv)
{
	char	**splited_args;
	char	*string;
	char	*tmp;
	int		i;

	string = ft_strdup("");
	if (!string)
		exit (EXIT_FAILURE);
	i = 0x1;
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i], " ");
		if (!tmp)
			exit(EXIT_FAILURE);
		string = ft_strjoin_and_free(string, tmp);
		if (!string)
			exit(EXIT_FAILURE);
		i++;
	}
	splited_args = ft_split(string, ' ');
	free(string);
	if (!splited_args)
		exit (EXIT_FAILURE);
	return (splited_args);
}
