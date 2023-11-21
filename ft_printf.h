/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:32:45 by sessarhi          #+#    #+#             */
/*   Updated: 2023/11/21 03:59:11 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
int		ft_printf(const char *, ...);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *count);
void	ft_putnbr_base(int nbr, char *base, int *count);
void	ft_putchar(char c, int *count);
#endif