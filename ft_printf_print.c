/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/20 06:03:59 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *s, int *len)
{
	int	i;
	
	if 	(!s)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	*len += i;	
}

void	ft_putadr(void *p, int *len)
{
	unsigned long long	adr;

	if 	(!p)
	{
		write(1, "(nil)", 5);
		*len += 5;
		return ;
	}
	adr = (unsigned long long)p;
	write(1, "0x", 2);
	*len += 2;
	ft_puthex(adr, len, 0);
}

void	ft_putnbr(int n, int *len)
{
	char	c;
	long	nl;
	
	nl = n;
	if (nl < 0)
	{		
		write(1, "-", 1);
		*len += 1;
		nl = -nl;
	}
	if (nl > 9)
		ft_putnbr(nl / 10, len);
	c = '0' + nl % 10;
	write(1, &c, 1);
	*len += 1;
}

void	ft_putnbr_u(unsigned int n, int *len)
{
	char	c;
	long	nl;
	
	nl = n;
	if (nl < 0)
	{		
		write(1, "-", 1);
		*len += 1;
		nl = -nl;
	}
	if (nl > 9)
		ft_putnbr(nl / 10, len);
	c = '0' + nl % 10;
	write(1, &c, 1);
	*len += 1;
}

void	ft_puthex(unsigned long long n, int *len, int type)
{
	char	*hex_min;
	char	*hex_maj;

	hex_min = "0123456789abcdef";
	hex_maj = "0123456789ABCDEF";
	if (n > 15)
		ft_puthex(n / 16, len, type);
	if (type == 0)
		write(1, &hex_min[n % 16], 1);
	else if (type == 1)
		write(1, &hex_maj[n % 16], 1);
	*len += 1;	
}