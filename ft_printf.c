/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:32:32 by sessarhi          #+#    #+#             */
/*   Updated: 2023/11/21 20:16:28 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  ft_format_type(const char *format, int *count , va_list args, int *i)
{
	if (format[*i + 1] == 'c')
		ft_putchar(va_arg(args,unsigned int),count);
	else if(format[*i + 1] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if(format[*i + 1] == 'i' ||format[*count + 1] == 'd')
		ft_putnbr_base(va_arg(args, int) , "0123456789",count);
	else if(format[*i + 1] == 'u')
		ft_putnbr_base(va_arg(args,unsigned int) , "0123456789",count);
	else if (format[*i + 1] == 'x')
		ft_putnbr_base(va_arg(args,int), "0123456789abcdef", count);
	else if (format[*i + 1] == 'X')
		ft_putnbr_base(va_arg(args,int), "0123456789ABCDEF", count);
	else if (format[*i + 1] == 'p')
	{
		ft_putstr("0x" , count);
		ft_putnbr_base(va_arg(args,int), "0123456789abcdef", count);
	}
	else if (format[*i + 1] == '%')
		ft_putchar('%' , count);
	*i += 1;
}
int	ft_printf(const char *format, ...)
{
	int	count;
	int i;
	va_list args;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args,format);
	
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_format_type(format, &count, args, &i);
		}
		else
			ft_putchar(format[i],&count);
		i++;
	}
	va_end(args);
	return (count);
}
