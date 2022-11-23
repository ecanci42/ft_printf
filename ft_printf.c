/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecanci <ecanci@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:30:28 by ecanci            #+#    #+#             */
/*   Updated: 2022/11/20 15:32:43 by ecanci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (write(1, "0x", 2) + ft_putptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		x;

	i = 0;
	x = 0;
	va_start(ap, str);
	while (str[i])
	{
		if ((str[i]) == '%')
			x += ft_type(ap, str[i++ + 1]);
		else
			x += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (x);
}
