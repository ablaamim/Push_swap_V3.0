/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:26:35 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/19 18:04:08 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# define HEX "0123456789abcdef"
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define BUFFER_SIZE 1024
# define OPEN_MAX 1024

typedef struct s_node
{
	int		nbr;
	int		index;
	bool	keep_a;
	void	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
	int		markup_head;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

/*
 * Orthodoxian sort, store infos about stacks
*/

typedef struct s_infos
{
	char	op[4];
	bool	top;
	int		n_op;
	int		ind;
	int		size;
}	t_infos;

typedef struct s_actions
{
	t_infos	a;
	t_infos	b;
	int		total;
	char	op_same[4];
	int		n_op_same;
}	t_actions;

/*
 * Parsing functions
*/
char	**ft_args_unified(int argc, char **argv);
void	ft_arguments_validator(int argc, char **argv);
void	ft_array_free(void **array);
bool	ft_parser(char **argv);

/*
 * Linked list util functions
*/
t_node	*ft_create_node(int numb);
void	ft_nodeadd_back(t_node **lst, t_node *new_node);
t_node	*ft_nodelast(t_node *lst);
void	ft_nodeadd_front(t_node **lst, t_node *new_node);

/*
 * Stack util functions
*/
void	ft_stacks_constructor(char **argv, t_stacks *stacks);
void	exit_program(t_stacks *stacks);
void	ft_clear_stacks(t_stacks *stacks);
void	ft_stack_free(t_node **lst, int size);
void	print_stacks(t_stacks stacks);

/*
 * Algorithm
*/
void	ft_algorithm(t_stacks *stacks);
bool	ft_sorted(t_stacks *stacks);
void	ft_sort_list_of_two(t_stacks *stacks);
void	ft_sort_list_of_three(t_stacks *stacks);
void	ft_sort_list_of_five(t_stacks *stacks);
void	ft_markup_elements(t_stack *a);
void	ft_find_markup(t_stack *a);
int		nodes_to_keep_a(t_stack *a, int markup_head, bool def);
void	push_to_stack_b(t_stacks *stacks);
void	push_to_stack_a(t_stacks *stacks);
void	exit_push_swap(t_stacks *stacks);
void	ft_optimize_actions_to_push_to_a(t_stacks *stacks, t_actions *def);
void	ft_attribute_operations(t_actions *def);
void	ft_operate_actions(t_stacks *stacks, t_actions *def);
void	ft_regularize_stack_a(t_stacks *stacks);
void	ft_steps_debuger(t_actions *def);

/*
 * Min/Max utils
*/
void	push_min_and_max_value_to_stack_b(t_stacks *stacks, int min, int max);
int		min_value(int n1, int n2);
int		get_min_value(t_node *tmp);
int		get_max_value(t_node *tmp);

/*
 * Operations
*/
void	call_operation(char *operation, t_stacks *stacks);
bool	ft_operations(char *op, t_stacks *stacks);
bool	ft_swap(t_stack *stack);
void	attribute_values(t_node *node, int *tab, int size);
bool	ft_rotate(t_stack *stack);
bool	ft_reverse_rotate(t_stack *stack);
bool	push(t_stack *to, t_stack *from);

/*
 * Libft utils
*/
int		get_next_line(int fd, char **line);
int		ft_printf(const char *fmt, ...);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_substr(char *s, int start, size_t len);

#endif
