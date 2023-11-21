/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:32:32 by sessarhi          #+#    #+#             */
/*   Updated: 2023/11/21 07:29:10 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  ft_format_type(int *count)
{
	if (format[*count + 1] = 'c')
		ft_putchar();
	else if(format[*count + 1] = 's')
		ft_putstr();
	else if(format[*count + 1] = 'i' ||format[*count + 1] = 'd')
		ft_putnbr_base();
	else if (format[*count + 1] = 'x')
	{
		ft_putstr("0x");
		ft_putnbr_base();
	}
	else if (format[*count + 1] = 'X')
	{
		ft_putstr("0X");
		ft_putnbr_base();
	}
}
int	ft_printf(const char *format, ...)
{
	int	count;
	int i;
	va_list args;

	i = 0;
	count = 0;
	if (!format)
		return -1;
	va_start(args,format);
	while (format[i])
	{
		va_arg(args, format);
		if (format[i] == '%')
		{
			ft_format_type(&i)
		}
		else
			ft_putchar(format[i],&count);
	}
	
}