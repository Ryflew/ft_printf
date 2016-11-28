/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:57:46 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/27 18:47:05 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"
#include "libft.h"

void	one_byte(char c)
{
	char	nbr;

	nbr = 2;
	nbr = (nbr << 6);
	nbr += c;
	ft_putchar(nbr);
}

void	four_bytes(wchar_t c)
{
	char	nbr;

	nbr = 30;
	nbr = (nbr << 3);
	nbr += (char)(c >> 18);
	c = (c << 14);
	c = (c >> 14);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 12);
	c = (c << 20);
	c = (c >> 20);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 6);
	c = (c << 26);
	c = (c >> 26);
	ft_putchar(nbr);
	one_byte(c);
}

void	three_bytes(wchar_t c)
{
	char	nbr;

	nbr = 14;
	nbr = (nbr << 4);
	nbr += (char)(c >> 12);
	c = (c << 20);
	c = (c >> 20);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 6);
	c = (c << 26);
	c = (c >> 26);
	ft_putchar(nbr);
	one_byte(c);
}

void	two_bytes(wchar_t c)
{
	char	nbr;

	nbr = 6;
	nbr = (nbr << 5);
	nbr += (char)(c >> 6);
	c = (c << 26);
	c = (c >> 26);
	ft_putchar(nbr);
	one_byte(c);
}

int		ft_s(wchar_t str, t_printf *elem)
{
	int		count;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = 0;
	if (elem)
	{
		// flags
	}
	ft_putnbr(str);
	// while (*str)
	// {
	// 	if ((*str >> 16) != 0)
	// 		four_bytes(*str);
	// 	else if ((*str >> 11) != 0)
	// 		three_bytes(*str);
	// 	else if ((*str >> 7) != 0)
	// 	{
	// 		two_bytes(*str);
	// 		ft_putendl("test");
	// 	}
	// 	else
	// 		ft_putchar(*str);
	// 	str++;
	// 	count++;
	// }
	return (count);
}