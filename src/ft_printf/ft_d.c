/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:31:29 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/29 20:30:29 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		check_plus_space(int nbr, t_printf *elem)
{
	int		count;

	count = 0;
	if (elem->flag_plus && nbr >= 0)
	{
		ft_putchar('+');
		count++;
	}
	else if (elem->flag_space && nbr >= 0)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int		check_complet_char(int nbr, int count, char letter, t_printf *elem)
{
	int	tmp;

	if (ft_countnbr(nbr) < (elem->width + count))
	{
		if (elem->precision > ft_countnbr(nbr))
		{
			tmp = elem->width - count - elem->precision;
			if (nbr < 0)
				tmp--;
		}
		else
			tmp = elem->width - count - ft_countnbr(nbr);
		while (tmp-- > 0)
			ft_putchar(letter);
		count = elem->width;
	}
	else
		count += ft_countnbr(nbr);
	return (count);
}

int		with_width(int nbr, t_printf *elem)
{
	int count;

	count = 0;
	if (elem->flag_minus)
	{
		count += check_plus_space(nbr, elem);
		ft_putnbrwp(nbr, elem->precision);
		count = check_complet_char(nbr, count, ' ', elem);
	}
	else if (elem->flag_zero)
	{
		count += check_plus_space(nbr, elem);
		count = check_complet_char(nbr, count, '0', elem);
		ft_putnbrwp(nbr, elem->precision);
	}
	else
	{
		count += check_plus_space(nbr, elem);
		count += check_complet_char(nbr, count, ' ', elem);
		ft_putnbrwp(nbr, elem->precision);
	}
	return (count);
}

int		ft_d(long nbr, t_printf *elem)
{
	int count;

	if (!nbr && !elem->precision)
		return (0);
	count = 0;
	if (elem->width)
		count = with_width(nbr, elem);
	else
	{
		count += check_plus_space(nbr, elem) + ft_countnbr(nbr);
		ft_putnbrwp(nbr, elem->precision);
		if (elem->precision >= ft_countnbr(nbr))
			count++;
	}
	if (elem->precision > ft_countnbr(nbr))
	{
		if (elem->width > elem->precision)
			count = elem->width;
		else if (nbr < 0)
			count = elem->precision + 1;
		else
			count = elem->precision;
	}
	return (count);
}
