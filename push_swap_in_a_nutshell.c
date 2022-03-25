/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_a_nutshell.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:22:05 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/25 13:46:26 by ablaamim         ###   ########.fr       */
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

enum e_order
{
	ASCENDING,
	DESCENDING
};

enum e_operation
{
	ROTATE,
	REVERSE_ROTATE,
	SWAP,
	PUSH
};

# define A		0
# define B		1
# define R		2

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
		return (0x0);
	i = 0x0;
	if (dstsize > 0x0)
	{
		while (src[i] && i + 0x1 < dstsize)
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

	copied = (char **)malloc(sizeof(char *) * (size + 0x1));
	if (!copied)
		return (NULL);
	i = 0x0;
	while (i < size)
	{
		copied[i] = (char *)malloc(sizeof(char) * (ft_strlen(args[i]) + 0x1));
		if (!copied[i])
		{
			while (--i >= 0x0)
				free(copied[i]);
			free(copied);
			return (NULL);
		}
		ft_strlcpy(copied[i], args[i], ft_strlen(args[i]) + 0x1);
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
	(*stack)->size = 0x0;
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
		(*stack)->range = 0x0;
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

	i = 0x0;
	sign = 0x1;
	total = 0x0;
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
	i = 0x0;
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

int	ft_check_args(t_data *data)
{
	t_list	*tmp;
	t_list	*iterator;

	tmp = data->a->list;
	while (tmp)
	{
		iterator = tmp->next;
		while (iterator)
		{
			if (tmp->number == iterator->number)
				return (0x0);
			iterator = iterator->next;
		}
		tmp = tmp->next;
	}
	return (0x1);
}

void	ft_stack_rotate(t_stack **stack)
{
	t_list	*moved;
	t_list	**list;

	moved = (*stack)->list;
	(*stack)->list = (*stack)->list->next;
	moved->next = NULL;
	list = &(*stack)->list;
	ft_list_add_back(list, moved);
}

void	ft_print_movement(int operation, int stack_id)
{
	if (operation == SWAP)
		write(1, "s", 1);
	else if (operation == PUSH)
		write(1, "p", 1);
	else if (operation == ROTATE)
		write(1, "r", 1);
	else if (operation == REVERSE_ROTATE)
		write(1, "rr", 2);
	if (stack_id == A)
		write(1, "a\n", 2);
	else if (stack_id == B)
		write(1, "b\n", 2);
	else if (stack_id == R && operation != SWAP)
		write(1, "r\n", 2);
	else
		write(1, "s\n", 2);
}

void	ft_rotate(t_data *data, int id, int is_print)
{
	if (id == A)
		ft_stack_rotate(&data->a);
	else if (id == B)
		ft_stack_rotate(&data->b);
	else if (id == R)
	{
		ft_stack_rotate(&data->a);
		ft_stack_rotate(&data->b);
	}
	if (is_print)
		ft_print_movement(ROTATE, id);
}

size_t	ft_list_len(t_list *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

void	ft_stack_reverse_rotate(t_stack **stack)
{
	t_list	*moved;
	t_list	*temp;
	size_t	list_size;
	size_t	i;

	list_size = ft_list_len((*stack)->list);
	moved = ft_list_last((*stack)->list);
	moved->next = (*stack)->list;
	(*stack)->list = moved;
	temp = (*stack)->list;
	i = 0;
	while (++i < list_size)
		temp = temp->next;
	temp->next = NULL;
}

void	ft_reverse_rotate(t_data *data, int id, int is_print)
{
	if (id == A)
		ft_stack_reverse_rotate(&data->a);
	else if (id == B)
		ft_stack_reverse_rotate(&data->b);
	else if (id == R)
	{
		ft_stack_reverse_rotate(&data->a);
		ft_stack_reverse_rotate(&data->b);
	}
	if (is_print)
		ft_print_movement(REVERSE_ROTATE, id);
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
	if (!ft_check_args(data))
		ft_end_program(data, 2);
	data->pos = (int *)malloc(sizeof(int) * 2);
	data->tmp = (int *)malloc(sizeof(int) * 2);
	data->ft[ROTATE] = ft_rotate;
	data->ft[REVERSE_ROTATE] = ft_reverse_rotate;
	if (!data->pos || !data->tmp)
		ft_end_program(data, 4);
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
