/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:26:35 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/04 17:37:21 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

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

/*
 * Stack util functions
*/
void	ft_stacks_constructor(char **argv, t_stacks *stacks);
void	exit_program(t_stacks *stacks);
void	print_stacks(t_stacks stacks);

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
