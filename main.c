/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:33:53 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/28 04:28:58 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/ft_printf.h"
#include <stdio.h>

int		main()
{
	int d = 42;
	printf("%.3%\n");
	d = ft_printf("%.5c", 0);
	ft_putchar(' ');
	ft_putnbr(d);
	return (0);
}