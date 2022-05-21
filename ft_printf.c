/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/21 02:19:43 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(va_list args, const char *format, int *len)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (*format == 'p')
		ft_putadr(va_arg(args, void *), len);
	else if (*format == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (*format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (*format == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	else if (*format == 'x')
		ft_puthex(va_arg(args, unsigned int), len, 0);
	else if (*format == 'X')
		ft_puthex(va_arg(args, unsigned int), len, 1);
	else if (*format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	if (!format)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*format)
	{
		if (*format == '%')
			print_args(args, ++format, &len);
		else
			ft_putchar(*format, &len);
	format++;
	}		
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	char 	*str;
	// char 	c;
	
	str = NULL;
	// c = 'c';
	int	i;
	
	i = ft_printf("%x", LONG_MAX);
	printf("%s", "\n----\n");
	printf("%x", LONG_MAX);
	printf("%s", "\n----\n");
	printf("nb caractere :%d\n", i); 
	return(0);
}*/
