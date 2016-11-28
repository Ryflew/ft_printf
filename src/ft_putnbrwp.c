/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrwp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 00:49:39 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/28 04:24:50 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrwp(int nbr, int precision)
{
	int count;

	if (precision && (nbr == -2147483648) && (precision > 10))
	{
		ft_putchar('-');
		count = precision - 10;
		while (count-- > 0)
			ft_putchar('0');
		ft_putnbr(2);
		nbr = 147483648;
	}
	else if (precision && (nbr != -2147483648))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		count = ft_countnbr(nbr);
		count = precision - count;
		while (count-- > 0)
			ft_putchar('0');
	}
	if (nbr || precision)
		ft_putnbr(nbr);
}