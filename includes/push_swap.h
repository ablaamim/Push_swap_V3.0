/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:26:35 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/11 16:30:53 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# define HEX "0123456789abcdef"

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

/*
 * Stack util functions
*/
void	ft_stacks_constructor(char **argv, t_stacks *stacks);
void	exit_program(t_stacks *stacks);
void	print_stacks(t_stacks stacks);
void	ft_clear_stacks(t_stacks *stacks);

/*
 * Algorithm
*/
void	ft_algorithm(t_stacks *stacks);
bool	ft_sorted(t_stacks *stacks);
void	ft_sort_list_of_two(t_stacks *stacks);

/*
 * Operations
*/
void	call_operation(char *operation, t_stacks *stacks);
bool	ft_operations(char *op, t_stacks *stacks);
bool	ft_swap(t_stack *stack);

/*
 * Libft utils
*/
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

#endif
