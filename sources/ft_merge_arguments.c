/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:35:01 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/06 20:25:05 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_merge_arguments(int argc, char **argv)
{
	char	*tmp;
	char	**argvalues_split;
	char	*str;
	int		i;

	i = 0x1;
	str = ft_strdup("");
	if (!str)
		exit(EXIT_FAILURE);
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i],  " ");
		if (!tmp)
			exit(EXIT_FAILURE);
		str = ft_strjoin_and_free(str, tmp);
		if (!str)
			exit(EXIT_FAILURE);
	}
	argvalues_split = ft_split(str, ' ');
	free(str);
	if (!argvalues_split)
		exit(EXIT_FAILURE);
	return (argvalues_split);
}
