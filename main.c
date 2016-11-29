/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:33:53 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/29 20:10:49 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/ft_printf.h"
// #include <stdio.h>
#include <locale.h>
int		main()
{
	// setlocale(LC_ALL, "");
	int d;
	d = printf("%ld", (long)2147483647 + 1);
	ft_putchar(' ');
	ft_putnbr(d);
	ft_putchar('\n');
	// d = ft_printf("%ld%ld", 0, 42);
	// ft_putchar(' ');
	// ft_putnbr(d);
	return (0);
}