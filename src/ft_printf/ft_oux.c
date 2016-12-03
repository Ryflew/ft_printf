/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:52:21 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/02 23:28:05 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		check_complet_charu(unsigned long nbr, int count, char letter, t_printf *elem)
{
	int	tmp;

	if (ft_countunbr(nbr) < (elem->width + count))
	{
		if (elem->precision > ft_countunbr(nbr))
			tmp = elem->width - count - elem->precision;
		else
			tmp = elem->width - count - ft_countunbr(nbr);
		while (tmp-- > 0)
			ft_putchar(letter);
		count = elem->width;
	}
	else
		count += ft_countunbr(nbr);
	return (count);
}

int		with_widthu(unsigned long nbr, t_printf *elem)
{
	int count;

	count = 0;
	if (elem->flag_minus)
	{
		ft_putunbrwp(nbr, elem->precision);
		count = check_complet_charu(nbr, count, ' ', elem);
	}
	else if (elem->flag_zero)
	{
		count = check_complet_charu(nbr, count, '0', elem);
		ft_putunbrwp(nbr, elem->precision);
	}
	else
	{
		count += check_complet_charu(nbr, count, ' ', elem);
		ft_putunbrwp(nbr, elem->precision);
	}
	return (count);
}

int		ft_u(unsigned long nbr, t_printf *elem)
{
	int count;

	count = 0;
	if (!elem->precision && !nbr)
		return (0);
	if (elem->width)
		count = with_widthu(nbr, elem);
	else
	{
		count = + ft_countunbr(nbr);
		ft_putunbrwp(nbr, elem->precision);
		if (elem->precision >= ft_countunbr(nbr))
			count++;
	}
	if (elem->precision > ft_countunbr(nbr))
	{
		if (elem->width > elem->precision)
			count = elem->width;
		else
			count = elem->precision;
	}
	return (count);
}

int		ft_oux(unsigned long nbr, char letter, t_printf *elem)
{
	if (letter == 'o' || letter == 'O')
		return (ft_o(nbr, elem));
	else if (letter == 'u' || letter == 'U')
		return (ft_u(nbr, elem));
	else
		return (ft_x(nbr, letter, elem));
	return (0);
}