/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:58:04 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/25 02:58:52 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libft.h"

int		ft_s(char *str)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		ft_putchar(str[i]);
		count++;
	}
	return (count);
}

int		ft_d(int nbr)
{
	int		count;

	count = 0;
	ft_putnbr(nbr);
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int		ft_c(int c)
{
	ft_putchar((char)(c & 255));
	return (1);
}

int		ft_percent()
{
	ft_putchar('%');
	return (1);
}