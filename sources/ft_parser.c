/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:40:56 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/04 20:49:41 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_is_numeric_param(char **argv)
{
	int	param;
	int	count_char;

	param = 0x0;
	while (argv[param])
	{
		count_char = 0x0;
		if (argv[param][count_char] == '-')
			count_char++;
		if (!ft_isdigit(argv[param][count_char]))
			return (false);
		while (argv[param][count_char])
		{
			if (!ft_isdigit(argv[param][count_char]))
				return (false);
			count_char++;
		}
		param++;
	}
	return (true);
}

bool	ft_check_range(char *str, char *limit)
{
	int	i;

	if (ft_strlen(str) > ft_strlen(limit))
		return (false);
	if (ft_strlen(str) < ft_strlen(limit))
		return (true);
	i = 0x0;
	while (str[i] == limit[i])
	{
		if (!str[i])
			return (true);
		i++;
	}
	if (str[i] > limit[i])
		return (false);
	return (true);
}

bool	ft_is_min_max(char **argv)
{
	int		param;
	char	*limit;

	param = 0x0;
	while (argv[param])
	{
		if (argv[param][0] == '-')
			limit = "-2147483648";
		else
			limit = "2147483647";
		if (!ft_check_range(argv[param], limit))
			return (false);
		param++;
	}
	return (true);
}

bool	ft_duplicated_param(char **argv)
{
	int	i;
	int	j;

	i = 0x0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_parser(char **argv)
{
	if (!ft_is_numeric_param(argv))
		return (false);
	if (!ft_is_min_max(argv))
		return (false);
	if (!ft_duplicated_param(argv))
		return (false);
	return (true);
}
