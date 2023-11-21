/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbaze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:09:42 by sessarhi          #+#    #+#             */
/*   Updated: 2023/11/21 03:57:19 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, int *count)
{
	size_t	lenght;
	size_t	nb;

	nb = nbr;
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