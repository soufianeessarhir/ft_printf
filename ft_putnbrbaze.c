/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbaze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:09:42 by sessarhi          #+#    #+#             */
/*   Updated: 2023/11/22 02:16:33 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long nb, char *base, int *count)
{
	long	lenght;
	
	lenght = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-',count);
		nb = -nb;
	}
	if (nb < lenght)
		ft_putchar(base[nb],count);
	else
	{
		ft_putnbr_base(nb / lenght, base ,count);
		ft_putnbr_base(nb % lenght, base,count);
	}
}