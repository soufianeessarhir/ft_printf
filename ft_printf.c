/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:32:32 by sessarhi          #+#    #+#             */
/*   Updated: 2023/11/23 21:57:29 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


void haha(unsigned long nb, int *count)
{
	char *p = "0123456789abcdef";
	if ( nb >= 16)
	{
		haha(nb / 16,count);
		haha(nb % 16,count);
	}
	else 
		ft_putchar(p[nb], count);
}
void ft_format_type(char c, int *count, va_list args)
{
    if (c == 'c')
        ft_putchar(va_arg(args, int), count);
    else if (c == 's')
        ft_putstr(va_arg(args, char *), count);
    else if (c == 'i' || c == 'd')
        ft_putnbr_base(va_arg(args, int), "0123456789", count);
    else if (c == 'u')
        ft_putnbr_base(va_arg(args, unsigned int), "0123456789", count);
    else if (c == 'x')
        ft_putnbr_base(va_arg(args, long), "0123456789abcdef", count);
    else if (c == 'X')
        ft_putnbr_base(va_arg(args, long), "0123456789ABCDEF", count);
    else if (c == 'p')
    {
        ft_putstr("0x", count);
        haha(va_arg(args,unsigned long) ,count);
    }
    else if (c == '%')
        ft_putchar('%', count);		
}

int ft_printf(const char *format, ...)
{
    int count;
    int i;
    va_list args;

    i = 0;
    count = 0;

    va_start(args, format);
	if (write(1, "", 1) == -1)
		return (-1);
    while (format[i])
    {
        if (format[i] == '%')
        {
			i++;
            if(format[i] == 'c')
				ft_putchar(va_arg(args, int), &count);
        }
        else 
            ft_putchar(format[i], &count);
        i++;
    }
    va_end(args);
    return (count);
}


int main()
{
       ft_printf("%c\n", '0');

}