/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_a_nutshell.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:22:05 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/25 13:32:28 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*list;
	size_t	size;
	size_t	range;
	int		order;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	float	coef[2];
	int		*pos;
	int		*tmp;
	int		operate;
	int		count;
	void	(*ft[2])(struct s_data *, int, int);
}	t_data;

enum e_order{
	ASCENDING,
	DESCENDING
};

void	ft_clear_list(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

void	ft_free_stack(t_stack *stack)
{
	if (stack->list)
		ft_clear_list(&stack->list);
	free(stack);
}

void	ft_free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_end_program(t_data *data, int exit_code)
{
	if (data)
	{
		if (data->a)
			ft_free_stack(data->a);
		if (data->b)
			ft_free_stack(data->b);
		if (data->pos)
			free(data->pos);
		if (data->tmp)
			free(data->tmp);
		if (data->args)
			ft_free_args(data->args);
		free(data);
	}
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s && s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	**ft_args_copy(char **args, int size)
{
	char	**copied;
	int		i;

	copied = (char **)malloc(sizeof(char *) * (size + 1));
	if (!copied)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copied[i] = (char *)malloc(sizeof(char) * (ft_strlen(args[i]) + 1));
		if (!copied[i])
		{
			while (--i >= 0)
				free(copied[i]);
			free(copied);
			return (NULL);
		}
		ft_strlcpy(copied[i], args[i], ft_strlen(args[i]) + 1);
		i++;
	}
	copied[i] = NULL;
	return (copied);
}

t_list	*ft_list_new(int number)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

t_list	*ft_list_last(t_list *list)
{
	t_list	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_list_add_back(t_list **list, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		temp = ft_list_last(*list);
		temp->next = new;
	}
}

void	ft_stack_range(t_stack **stack)
{
	t_list	*list;
	int		min;
	int		max;

	list = (*stack)->list;
	(*stack)->size = 0;
	if (list)
	{
		min = (*stack)->list->number;
		max = (*stack)->list->number;
		while (list)
		{
			(*stack)->size++;
			if (list->number > max)
				max = list->number;
			if (list->number < min)
				min = list->number;
			list = list->next;
		}
		(*stack)->range = (size_t)(max - min);
	}
	else
		(*stack)->range = 0;
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi_mod(t_data *data, int position)
{
	size_t	i;
	int		sign;
	long	total;

	i = 0;
	sign = 1;
	total = 0;
	if (data->args[position][i] == '+' || data->args[position][i] == '-')
		if (data->args[position][i++] == '-')
			sign *= (-1);
	if (!ft_isdigit(data->args[position][i]))
		ft_end_program(data, 6);
	while (data->args[position][i] >= '0' && data->args[position][i] <= '9')
	{
		if (sign == -1)
			total = total * 10 - (data->args[position][i] - '0');
		else
			total = total * 10 + (data->args[position][i] - '0');
		if (total < -2147483648 || total > 2147483647)
			ft_end_program(data, 6);
		i++;
	}
	if (!ft_isdigit(data->args[position][i]) && data->args[position][i] != 0)
		ft_end_program(data, 6);
	return ((int)total);
}

void	ft_get_stack_list(t_data *data)
{
	t_list	*new;
	int		i;

	data->a->list = NULL;
	i = 0;
	while (data->args[i])
	{
		new = ft_list_new(ft_atoi_mod(data, i));
		if (!new && data->a->list)
		{
			ft_clear_list(&data->a->list);
			break ;
		}
		ft_list_add_back(&data->a->list, new);
		i++;
	}
}

void	ft_init_stacks(t_data *data)
{
	data->a = (t_stack *)malloc(sizeof(t_stack));
	data->b = (t_stack *)malloc(sizeof(t_stack));
	if (!data->a || !data->b)
		ft_end_program(data, 4);
	ft_get_stack_list(data);
	if (!data->a->list)
		ft_end_program(data, 4);
	ft_stack_range(&data->a);
	ft_stack_range(&data->b);
	data->a->order = ASCENDING;
	data->b->order = DESCENDING;
}

t_data	*ft_data_initializer(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof(t_data));
	if (!data)
		ft_end_program(data, 3);
	if (argc - 1 == 1)
		data->args = ft_split(argv[1], ' ');
	else
		data->args = ft_args_copy(&argv[1], argc - 1);
	ft_init_stacks(data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc - 1 == 0x0)
		exit (EXIT_FAILURE);
	data = ft_data_initializer(argc, argv);
	ft_end_program(data, 0);
	return (EXIT_SUCCESS);
}
