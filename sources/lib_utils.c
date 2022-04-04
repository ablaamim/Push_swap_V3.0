/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:37:01 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/04 13:32:40 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0x0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	if (!str)
		return (0x0);
	i = 0;
	dup = (char *) malloc (sizeof (char) * (ft_strlen(str) + 1));
	if (!dup)
		return (0x0);
	while (i < ft_strlen(str))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (0x0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	joined = (char *) malloc (sizeof (char) * (lens1 + lens2 + 1));
	if (!joined)
		return (0x0);
	i = 0x0;
	j = 0x0;
	while (s1[i])
	{
		joined[j++] = s1[i];
		i++;
	}
	i = 0x0;
	while (s2[i])
	{
		joined[j++] = s2[i];
		i++;
	}
	joined[j] = '\0';;
	return (joined);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (0x0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	joined = (char *) malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (!joined)
		return (0x0);
	i = 0x0;
	j = 0x0;
	while (s1[i])
	{
		joined[j++] = s1[i];
		i++;
	}
	i = 0x0;
	while (s2[i])
	{
		joined[j++] = s2[i];
		i++;
	}
	joined[j] = '\0';
	free(s1);
	free(s2);
	return (joined);
}
