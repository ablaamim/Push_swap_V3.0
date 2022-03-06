/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_a_nutshell.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:52:43 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/06 18:33:11 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // In order to use write system call
#include <stdlib.h> // Malloc system call inclusion

/*
 * The subject restricts the use of a stack,
 * so i implemented it in a sophisticated way
*/

/*
 * Linked list 
 * to implement a stack
*/
typedef struct s_node
{
	int		number;
	int		index;
	void	*next;
}	t_node;

/*
 * Stack implementation
*/
typedef struct s_stack
{
	t_node	*head;
	size_t	size;
}	t_stack;

/*
 * Both stacks a and b
*/
typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

/*
 * Calculates the length of a string and return it
*/
int	ft_strlen(char	*str)
{
	int	len = 0x0;
	if (!str)
		return (0x0);
	while (str[len])
		len++;
	return (len);
}

/*
 * Duplicates a string using malloc and returns an exact copy of it
*/
char	*ft_strdup(char *str)
{
	int	i = -1;
	if (!str)
		return (0x0);
	char	*new = (char *) malloc (sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (0x0);
	while (++i < ft_strlen(str))
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

/*
 * Joins two strings and returns the joined result
*/
char	*ft_strjoin(char *s1, char *s2)
{
	int	i = 0x0;
	int	j = 0x0;
	int	ls1 = ft_strlen(s1);
	int	ls2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (0x0);
	char	*joined = (char *) malloc (sizeof(char) * (ls1 + ls2 + 1));
	if (!joined)
		return (0x0);
	while (s1[j])
	{
		joined[i++] = s1[j];
		j++;
	}
	j = 0x0;
	while (s2[j])
	{
		joined[i++] = s2[j];
		j++;
	}
	joined[i] = '\0';
	return (joined);
}

/*
 * Join two strings and return joined version after memory free()
*/
char	*ft_strjoin_and_free(char *s1, char *s2)
{
	int	i = 0x0;
	int	j = 0x0;
	int	ls1 = ft_strlen(s1);
	int	ls2 = ft_strlen(s2);

	if (!ls1 || !ls2)
		return (0x0);
	char	*joined = (char *) malloc (sizeof(char) * (ls1 + ls2 + 1));
	if (!joined)
		return (0x0);
	while (s1[j])
	{
		joined[i++] = s1[j];
		j++;
	}
	j = 0x0;
	while (s2[j])
	{
		joined[i++] = s2[j];
		j++;
	}
	joined[i] = '\0';
	free(s1);
	free(s2);
	return (joined);
}

int	ft_count_words(char *s, char c)
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

char	*ft_make_words(char *word, char *s, int j, int word_ln)
{
	int	i;

	i = 0;
	while (word_ln > 0)
		word[i++] = s[j - word_ln--];
	word[i] = '\0';
	return (word);
}

char	**ft_split_words(char **res, char *s, char c, int word_ct)
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
	res[i] = '\0';
	return (res);
}

/*
 * Split a string by a char delimiter and return an array of strings
*/
char	**ft_split(char *s, char c)
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

/*
 * Join argvalues inside a temporary string by space,
 * then join them again into another string,
 * then i split them by space and store the output in
 * an array of strings
*/
char	**ft_merge_argvalues(int argc, char **argv)
{
	char	*string;
	char	*tmp;
	char	**split_argvalues;
	int		i = 0x1;

	string = ft_strdup("");
	if (!string)
		exit(EXIT_FAILURE);
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i], " ");
		if (!tmp)
			exit(EXIT_FAILURE);
		string = ft_strjoin_and_free(string, tmp);
		if (!string)
			exit(EXIT_FAILURE);
		i++;
	}
	split_argvalues = ft_split(string, ' ');
	free(string);
	if (!split_argvalues)
		exit (EXIT_FAILURE);
	return (split_argvalues);
}

/*
 * Display character on
 * stdout using write system call
*/
void	ft_putchar(char c){write(1, &c ,1);}

/*
 * Display a string on stdout
 * using ft_putchar
*/
void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

/*
 * Prints an integer on stdout using recursion
*/
void	ft_putnbr(int nb)
{
	long	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}
/*
 * Printing arguments entered by the user
*/
void	ft_print_arguments(int argc, char **argv)
{
	int	i = 0x1;
	while (i < argc)
	{
		ft_putstr("argv[");
		ft_putnbr(i);
		ft_putstr("] : ");
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
 * Entry point of my program : it is supposed to enter dynamically user arguments
 * and handle couple of error handling cases, argvalues must be integers, 
 * must not be duplicated, also must be inclusive in integer's range 
*/

int	main(int argc, char **argv)
{
	//char	**split_argvalues;

	//split_argvalues = ft_merge_argvalues(argc, argv);
	/*Split test
	char	str[] = "a b c d";
	int	i = 0x0;
	char	**split = ft_split(str, ' ');

	while (i < 4)
	{
		ft_putstr(split[i]);
		i++;
	}
	*/
	ft_putstr("********************************\n");
	ft_putstr("    ~welcome to push_swap~\n");
	ft_putstr("********************************\n");
	ft_putstr("You entered the following values :\n");
	ft_print_arguments(argc, argv);

	char	**split_argvalues;
	/*
	 * Retrive argument values, join them then split them by space
	*/
	split_argvalues = ft_merge_argvalues(argc, argv);
	//while (1); // Infinite loop for leaks checking
	return (EXIT_SUCCESS);
}
