/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:05:13 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/19 11:07:45 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_breakline(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != c)
		return (-1);
	return (i);
}

static int	ft_newline(char **p_line, char **line, int i, char *buffer)
{
	char	*tmp;

	*line = ft_substr(*p_line, 0, i);
	tmp = ft_substr(*p_line, (i + 1), ft_strlen(*p_line) - i);
	free(*p_line);
	*p_line = tmp;
	if (*p_line && *p_line[0] == '\0')
	{
		free(*p_line);
		*p_line = NULL;
	}
	free(buffer);
	buffer = NULL;
	return (1);
}

static int	ft_endoffile(char **p_line, char **line, char *buffer)
{
	if (*p_line)
	{
		*line = ft_strdup(*p_line);
		free(*p_line);
		*p_line = NULL;
		free(buffer);
		buffer = NULL;
		return (0);
	}
	*line = ft_strdup("");
	free(buffer);
	buffer = NULL;
	return (0);
}

static int	ft_gnl(char **p_line, char **line, int fd, char *buffer)
{
	char		*tmp;
	int			i;
	int			r_byte;

	r_byte = read(fd, buffer, BUFFER_SIZE);
	while (r_byte > 0)
	{
		buffer[r_byte] = '\0';
		if (!(*p_line))
			*p_line = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(*p_line, buffer);
			free(*p_line);
			*p_line = tmp;
		}
		i = ft_breakline(*p_line, '\n');
		if (i >= 0)
			return (ft_newline(p_line, line, i, buffer));
		r_byte = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_endoffile(p_line, line, buffer));
}

int	get_next_line(int fd, char **line)
{
	static char	*p_line[OPEN_MAX];
	char		*buffer;
	int			i;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (0);
	if (p_line[fd])
	{
		i = ft_breakline(p_line[fd], '\n');
		if (i >= 0)
			return (ft_newline(&p_line[fd], line, i, buffer));
	}
	return (ft_gnl(&p_line[fd], line, fd, buffer));
}
