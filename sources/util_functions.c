/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:36:50 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/06 20:31:19 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0x0);
	len = 0x0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = -1;
	new = (char *) malloc (sizeof(char) * ft_strlen(str));
	if (!new)
		return (0x0);
	while (++i < ft_strlen(str))
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;
	int		ls1;
	int		ls2;

	i = 0x0;
	j = 0x0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	joined = (char *) malloc (sizeof(char) * (ls1 + ls2 + 1));
	if (!joined)
		return (0x0);
	while (s1[j])
	{
		joined[i++] = s1[j];
		j++;
	}
	j = 0x0;
	while (s2[j])
	{
		joined[i++] = s2[j];
		j++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	int		i;
	int		j;
	int		ls1;
	int		ls2;
	char	*joined;

	i = 0x0;
	j = 0x0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	joined = (char *) malloc (sizeof(char) * (ls1 + ls2 + 1));
	while (s1[j])
	{
		joined[i++] = s1[j];
		j++;
	}
	j = 0x0;
	while (s2[j])
	{
		joined[i++] = s2[j];
		j++;
	}
	joined[i] = '\0';
	free(s1);
	free(s2);
	return (joined);
}
