/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:26:35 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/03 15:40:33 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

/*
 * Parsing functions
*/
char	**ft_args_unified(int argc, char **argv);
void	ft_arguments_validator(int argc, char **argv);
void	ft_array_free(void **array);
bool	ft_parser(char **argv);
/*
 * Libft utils
*/
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	**ft_split(char const *s, char c);

#endif
