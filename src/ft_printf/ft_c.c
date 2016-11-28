/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:05:36 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/28 04:26:56 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_c(char c, t_printf *elem)
{
	int		count;

	count = 0;
	if (elem->flag_sharp || elem->flag_zero || elem->flag_plus ||
		elem->flag_space || elem->length)
		return (-1);
	if (elem->width)
	{
		count = elem->width;
		if (elem->flag_minus)
			ft_putchar(c);
		while (--count)
			ft_putchar(' ');
		if (!elem->flag_minus)
			ft_putchar(c);			
		return (elem->width);
	}
	ft_putchar(c);
	return (1);
}