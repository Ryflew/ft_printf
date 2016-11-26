/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:35:37 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/26 01:48:51 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"

int		del_elem(t_printf elem, int nbr)
{
	free(elem);
	return (nbr);
}

int		go_args(char *str, va_list ap)
{
	t_printf	*elem;

	if (++str == '\0')
		return (0);
	va_arg(ap, int);
	elem = (t_printf)malloc(sizeof(t_printf));	
	if (!(check_flags(str, elem)))
		return (del_elem(elem, -1));
	else if (!check_width(str, elem))
		return (del_elem(elem, -1));
	else if (!check_precision(str, elem))
		return (del_elem(elem, -1));
	else if (!check_len(str, elem))
		return (del_elem(elem, -1));
	return (-1);
}

int		go_solve(char *str, va_list ap, int bytes)
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
		if ((count = go_args(str, ap)) == -1)
			return (-1);
		else
			return (go_solve(str, ap, bytes + count));
	}
}

int		ft_printf(const char * restrict format, ...)
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