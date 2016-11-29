/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:35:37 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/29 18:04:53 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"

int			del_elem(t_printf *elem, int nbr)
{
	// if (elem->length != NULL)
		// free(elem->length);
	free(elem);
	return (nbr);
}

t_printf	*creat_elem(void)
{
	t_printf	*elem;

	elem = (t_printf*)malloc(sizeof(t_printf));
	elem->flag_sharp = 0;
	elem->flag_zero = 0;
	elem->flag_minus = 0;
	elem->flag_plus = 0;
	elem->flag_space = 0;
	elem->width = 0;
	elem->precision = -1;
	elem->length = NULL;
	elem->conversion = 0;
	return (elem);
}

int			go_args(char **str, va_list ap)
{
	t_printf	*elem;
	int			count;

	if (++(*str) == '\0')
		return (0);
	elem = creat_elem();
	if (!(check_flags(str, elem)))
		return (del_elem(elem, -1));
	if (!check_width(str, elem))
		return (del_elem(elem, -1));
	if (!check_precision(str, elem))
		return (del_elem(elem, -1));
	if (!check_len(str, elem))
		return (del_elem(elem, -1));
	if (!check_conv(str, elem))
		return (del_elem(elem, 0));
	count = treat(elem, ap);
	return (del_elem(elem, count));
}

int			go_solve(char *str, va_list ap, int bytes)
{
	char		*tmp;
	int			count;

	if (*str == '\0')
		return (bytes);
	tmp = ft_strchr(str, '%');
	if (!tmp)
	{
		ft_putstr(str);
		return (bytes + ft_strlen(str));
	}
	else if (tmp > str)
	{
		ft_putnstr(str, tmp - str);
		return (go_solve(tmp, ap, bytes + (tmp - str)));
	}
	else
	{
		if ((count = go_args(&str, ap)) == -1)
			return (-1);
		else
			return (go_solve(str, ap, bytes + count));
	}
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = go_solve((char*)format, ap, 0);
	va_end(ap);
	return (count);
}
