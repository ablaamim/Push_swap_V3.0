/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_a_nutshell.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:44:44 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/07 21:22:13 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#define hex "0123456789abcdef"

typedef struct s_node
{
	int		nbr;
	int		index;
	int		keep_a;
	void	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
	bool	markup_head;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

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
	ft_clear_stacks(&stacks);
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
	ft_clear_stacks(&stacks);
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
	ft_clear_stacks(&stacks);
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	ft_clear_stacks(&stacks);
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pd;
	unsigned char	*ps;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	i = 0;
	pd = (unsigned char *) dst;
	ps = (unsigned char *) src;
	while (n > 0)
	{
		pd[i] = ps[i];
		i++;
		n--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	if (dst == NULL && src == NULL)
		return (NULL);
	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	i = 1;
	if (srcc < dstc)
	{
		while (i <= len)
		{
			dstc[len - i] = srcc[len - i];
			i++;
		}
	}
	else
		ft_memcpy(dstc, srcc, len);
	return (dst);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

t_node	*ft_create_node(int numb)
{
	t_node	*elem;

	elem = ft_calloc(0x1, sizeof(t_node));
	if (!elem)
		return (0x0);
	elem->nbr = numb;
	elem->next = NULL;
	return (elem);
}

void	ft_stack_free(t_node **lst, int size)
{
	t_node	*to_free;
	int	i;

	to_free = *lst;
	if (!lst || *lst)
		return ;
	i = 0x0;
	while (i < size)
	{
		*lst = to_free->next;
		free(to_free);
		to_free = *lst;
		i++;
	}
	*lst = NULL;
}

void	ft_clear_stacks(t_stacks *stacks)
{
	ft_stack_free(&stacks->a.head, stacks->a.size);
	ft_stack_free(&stacks->b.head, stacks->a.size);
}

void	exit_program(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	ft_clear_stacks(stacks);
	exit(EXIT_FAILURE);
}

void	ft_nodeadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_stacks_constructor(char **argv, t_stacks *stacks)
{
	t_node	*new_node;

	stacks->a = (t_stack) {0};
	stacks->b = (t_stack) {0};
	while (argv[stacks->a.size])
	{
		new_node = ft_create_node(ft_atoi(argv[stacks->a.size]));
		if (!new_node)
			exit_program(stacks);
		ft_nodeadd_back(&stacks->a.head, new_node);
		(stacks->a.size)++;
	}
}

int	ft_putchar_printf(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_printf(char *str)
{
	int	len;

	len = 0x0;
	if (str == NULL)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	while (*str)
		len += ft_putchar_printf(*str++);
	return (len);
}

int	ft_putnbr_printf(long long nb, int base)
{
	int len = 0x0;
	if (nb < 0)
	{
		nb = -nb;
		len+=ft_putchar_printf('-')
	;}
	if (nb >= base)
		len += ft_putnbr_printf(nb / base, base);
	len += ft_putchar_printf(hex[nb % base]);
	return (len);
}
int	ft_vaprintf(va_list ap, const char *fmt)
{
	int len = 0x0; char c;
	while (*fmt)
	{
		c = *fmt++;
		if (c != '%')
			len += ft_putchar_printf(c);
		else
		{
			c = *fmt++;
			if (c == 's')
				len += ft_putstr_printf(va_arg(ap, char *));
			if (c == 'd')
				len+=ft_putnbr_printf((long long)va_arg(ap, int), 10);
		}
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	int len;
	va_list ap;

	len = 0x0;
	va_start(ap, fmt);
	len += ft_vaprintf(ap, fmt);
	va_end(ap);
	return (len);
}

void	print_stacks(t_stacks stacks)
{
	int	i;

	i = 0;
	ft_printf("\nsize:\t%d\t%d\n-----\nstack:", stacks.a.size, stacks.b.size);
	while (i < stacks.a.size || i < stacks.b.size)
	{
		if (i < stacks.a.size)
		{
			ft_printf("\t%d", stacks.a.head->nbr);
			if (stacks.a.head->next)
				stacks.a.head = stacks.a.head->next;
		}
		else
			ft_printf("\t");
		if (i < stacks.b.size)
		{
			ft_printf("\t%d", stacks.b.head->nbr);
			if (stacks.b.head->next)
				stacks.b.head = stacks.b.head->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\t_\t_\n\ta\tb\n> ");
}

int	main(int argc, char **argv)
{
	char		**splited_argv;
	t_stacks	stacks;

	splited_argv = ft_args_unified(argc, argv);
	ft_arguments_validator(argc, splited_argv);
	ft_putstr("******************************************\n");
	ft_putstr("         Weclome to push_swap           \n");
	ft_putstr("******************************************\n\n");
	ft_putstr("------------------------------------------\n");
	ft_putstr("        Arguments you entered are : \n");
	ft_putstr("------------------------------------------\n");
	ft_print_args(splited_argv);
	ft_stacks_constructor(splited_argv, &stacks);
	ft_putstr("------------------------------------------\n");
	ft_putstr("          Stack constructor : \n");
	ft_putstr("------------------------------------------\n");
	print_stacks(stacks);
	ft_putstr("\n------------------------------------------\n");
	return (EXIT_SUCCESS);
}
