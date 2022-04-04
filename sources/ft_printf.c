/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:22:13 by ablaamim          #+#    #+#             */
/*   Updated: 2022/04/04 20:51:03 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int	len;

	len = 0x0;
	if (nb < 0)
	{
		nb = -nb;
		len += ft_putchar_printf('-');
	}
	if (nb >= base)
		len += ft_putnbr_printf(nb / base, base);
	len += ft_putchar_printf(HEX[nb % base]);
	return (len);
}

int	ft_vaprintf(va_list ap, const char *fmt)
{
	int		len;
	char	c;

	len = 0x0;
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
				len += ft_putnbr_printf((long long)va_arg(ap, int), 10);
		}
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;

	len = 0x0;
	va_start(ap, fmt);
	len += ft_vaprintf(ap, fmt);
	va_end(ap);
	return (len);
}
