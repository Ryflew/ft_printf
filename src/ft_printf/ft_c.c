/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:05:36 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/29 18:02:19 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"
#include "libft.h"

int		ft_count_unicode(wchar_t c)
{
	if ((c >> 16) != 0)
		return (4);
	else if ((c >> 11) != 0)
		return (3);
	else if ((c >> 7) != 0)
		return (2);
	else
		return (1);
}

int		ft_count_multiple_unicode(wchar_t *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
		count += ft_count_unicode(str[i]);
	return (count);
}

void	ft_unicode(unsigned int c)
{
	if ((c >> 16) != 0)
		four_bytes(c);
	else if ((c >> 11) != 0)
		three_bytes(c);
	else if ((c >> 7) != 0)
		two_bytes(c);
	else
		ft_putchar(c);
}

int		ft_cwl(wint_t c, t_printf *elem)
{
	int count;

	if (elem->width)
	{
		if (ft_count_unicode(c) > 1)
			count = elem->width - ft_count_unicode(c);
		else
			count = elem->width - 1;
		if (elem->flag_minus)
			ft_unicode(c);
		while (count-- > 0)
			ft_putchar(' ');
		if (!elem->flag_minus)
			ft_unicode(c);
	}
	else
		ft_unicode(c);
	count = ft_count_unicode(c);
	if (elem->width > count)
		return (elem->width);
	return (count);
}

int		ft_c(int c, t_printf *elem)
{
	int		count;
	unsigned char	cha;

	count = 0;
	if (elem->flag_sharp || elem->flag_zero ||
		elem->flag_space)
		return (-1);
	cha = c & 255;
	if (elem->width)
	{
		count = elem->width;
		if (elem->flag_minus)
			ft_putchar(cha);
		while (--count)
			ft_putchar(' ');
		if (!elem->flag_minus)
			ft_putchar(cha);
		return (elem->width);
	}
	ft_putchar(cha);		
	return (1);
}
