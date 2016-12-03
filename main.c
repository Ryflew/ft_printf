/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:33:53 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/04 00:37:05 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/ft_printf.h"
#include <locale.h>
int		main()
{
	// setlocale(LC_ALL, "");
	int d = 42;
	d = ft_printf("Yolo %lh.1#d", 42);
	// ft_putchar(' ');
	ft_putnbr(d);
	ft_putchar('\n');
	d = printf("Yolo %lh.1#d", 42);
	// ft_putnbr(d);
	return (0);
}