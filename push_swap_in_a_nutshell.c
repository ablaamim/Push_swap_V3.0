/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_a_nutshell.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:44:44 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/04 16:35:09 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

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
	dup = (char *) malloc (sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (0x0);
	i = 0x0;
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
	return (joined);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	i = 0x0;
	j = 0x0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	joined = (char *)malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (!joined)
		return (0x0);
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

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_make_words(char *word, char const *s, int j, int word_ln)
{
	int	i;

	i = 0;
	while (word_ln > 0)
		word[i++] = s[j - word_ln--];
	word[i] = '\0';
	return (word);
}

static char	**ft_split_words(char **res, char const *s, char c, int word_ct)
{
	int	i;
	int	j;
	int	word_ln;

	i = 0;
	j = 0 ;
	word_ln = 0;
	while (s[j] && i < word_ct)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_ln++;
		}
		res[i] = (char *)malloc(sizeof(char) * (word_ln + 1));
		if (!res[i])
			return (NULL);
		ft_make_words (res[i], s, j, word_ln);
		word_ln = 0;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		word_ct;
	char	**res;

	if (s == NULL)
		return (NULL);
	word_ct = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_ct + 1));
	if (!res)
		return (NULL);
	ft_split_words (res, s, c, word_ct);
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0x0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**ft_args_unified(int argc, char **argv)
{
	char	*string;
	char	*tmp;
	char	**splited_argv;
	int		i;
	int		param;

	param = 0x0;
	while (argv[param])
	{
		if (!ft_strcmp(argv[param], ""))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		param++;
	}
	string = ft_strdup("");
	if (!string)
		exit(EXIT_FAILURE);
	i = 0x1;
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i], " ");
		if (!tmp)
			exit (EXIT_FAILURE);
		string = ft_strjoin_and_free(string, tmp);
		if (!string)
			exit (EXIT_FAILURE);
		i++;
	}
	splited_argv = ft_split(string, ' ');
	free(string);
	if (!splited_argv)
		exit (EXIT_FAILURE);
	return (splited_argv);
}

void	ft_array_clear(void **array)
{
	int	len;
	int	i;

	len = 0x0;
	if (!array)
		return ;
	while (array[len])
		len++;
	i = 0x0;
	while (i < len)
	{
		free(array[i]);
		array[i] = 0x0;
		i++;
	}
	free(array);
	array = 0x0;
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

bool	ft_is_numeric(char **argv)
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

	i = 0x0;
	if (ft_strlen(str) > ft_strlen(limit))
		return (false);
	if (ft_strlen(str) < ft_strlen(limit))
		return (true);
	while (ft_strlen(str) == ft_strlen(limit))
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

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	if (!str)
		return (0x0);
	sign = 0x1;
	res = 0x0;
	while (*str >= 7 && *str <= 14)
		str++;
	if (*str == '-')
		sign *= -1;
	while (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}

bool	ft_is_duplicated(char **argv)
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

bool	ft_parse(char **argv)
{
	if (!ft_is_numeric(argv))
		return (false);
	if (!ft_is_min_max(argv))
		return (false);
	if (!ft_is_duplicated(argv))
		return (false);
	return (true);
}

void	ft_arguments_validator(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_array_clear((void **) argv);
		exit (EXIT_SUCCESS);
	}
	if (!ft_parse(argv))
	{
		ft_array_clear((void **) argv);
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_print_args(char **argv)
{
	int	param;

	param = 0x0;
	while (argv[param])
	{
		ft_putstr(argv[param]);
		ft_putchar('\n');
		param++;
	}
}

int	main(int argc, char **argv)
{
	char	**splited_argv;

	splited_argv = ft_args_unified(argc, argv);
	ft_arguments_validator(argc, splited_argv);
	ft_putstr("****************************************\n");
	ft_putstr("         Weclome to push_swap           \n");
	ft_putstr("****************************************\n\n");
	ft_putstr("Arguments you entered are : \n");
	ft_print_args(splited_argv);
	return (EXIT_SUCCESS);
}
