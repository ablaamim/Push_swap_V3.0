/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_mem_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:59:56 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/04 17:01:56 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
