/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 04:04:52 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/28 04:29:49 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"

int		get_ft(va_list ap, t_printf *elem, char c)
{
	//if (c == 's')
	//	return(ft_s(va_arg(ap, wchar_t), elem));
	// else if (c == 'S')
	// 	return(ft_smaj(elem));
	// else if (c == 'p')
	// 	return(ft_p(elem));
	if (c == 'd')
		return(ft_d(va_arg(ap, int), elem));
	// else if (c == 'D')
	// 	return(ft_dmaj(elem));
	// else if (c == 'i')
	// 	return(ft_i(elem));
	// else if (c == 'o')
	// 	return(ft_o(elem));
	// else if (c == 'O')
	// 	return(ft_omaj(elem);)
	// else if (c == 'u')
	// 	return(ft_u(elem));
	// else if (c == 'U')
	// 	return(ft_U(elem));
	// else if (c == 'x')
	// 	return(ft_x(elem));
	// else if (c == 'X')
	// 	return(ft_xmaj(elem));
	else if (c == 'c')
		return(ft_c(va_arg(ap, int), elem));
	/*else if (c == 'C')
		return(ft_cmaj(elem));*/
	else if (c == '%')
		return (ft_percent());
	return (-1);
}

int		treat(t_printf *elem, va_list ap)
{
	int		count;

	count = get_ft(ap, elem, elem->conversion);
	if (count == -1)
		return (-1);
	else
		return (count);
}