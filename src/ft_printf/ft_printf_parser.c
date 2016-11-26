/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:51:33 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/26 01:47:27 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*check_flags(char *str, t_printf elem)
{
	if (*str == '#' || *str == ' ' || *str == '+' || *str == '-' || *str == '0')
	{
		if (*str == '#')
			elem->flag_sharp = 1;
		else if (*str == '0')
			elem->flag_zero = 1;
		else if (*str == '-')
			elem->flag_minus = 1;
		else if (*str == '+')
			elem->flag_plus = 1;
		else if (*str == ' ')
			elem->flag_space = 1;
		return (check_flags(++str, elem));
	}
	else
		return (str);
}

char	*check_width(char *str, t_printf *elem)
{
	char	*tmp;
	int		i;

	if ((*str < 48) || (*str > 57))
		return (str);
	i = 0;
	while ((str[i] >= 48) && (str[i] <= 57))
		i++;
	tmp = (char*)malloc(sizeof(char) * (i + 1));
	i = -1;
	while ((*str >= 48) && (*str <= 57))
	{
		tmp[++i] = *str;
		str++;
	}
	tmp[++i] = '\0';
	elem->width = ft_atoi(tmp);
	free(tmp);
	return (str);
}

char	*check_precision(char *str, t_printf elem)
{
	char	*tmp;
	int		i;

	if (*str != '.')
		return (str);
	str++;
	if (*str == '-')
		return (NULL);
	if ((*str < 48) || (*str > 57))
		return (str);
	i = 0;
	while ((str[i] >= 48) && (str[i] <= 57))
		i++;
	tmp = (char*)malloc(sizeof(char) * (i + 1));
	i = -1;
	while ((*str >= 48) && (*str <= 57))
	{
		tmp[++i] = *str;
		str++;
	}
	tmp[++i] = '\0';
	elem->precision = ft_atoi(tmp);
	free(tmp);
	return (str);
}