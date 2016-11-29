/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:42:59 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/29 11:22:59 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_percent(t_printf *elem)
{
	int count;

	count = 0;
	if (elem->width)
	{
		count = elem->width;
		if (elem->flag_minus)
			ft_putchar('%');
		while ((elem->width-- - 1) > 0)
			ft_putchar(' ');
		if (!elem->flag_minus)
			ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}
