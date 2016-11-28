/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:51:33 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/28 04:14:46 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

char	*check_flags(char **str, t_printf *elem)
{
	if (**str == '#' || **str == ' ' || **str == '+' || **str == '-' ||
		**str == '0')
	{
		if (**str == '#')
			elem->flag_sharp = 1;
		else if (**str == '0')
			elem->flag_zero = 1;
		else if (**str == '-')
			elem->flag_minus = 1;
		else if (**str == '+')
			elem->flag_plus = 1;
		else if (**str == ' ')
			elem->flag_space = 1;
		(*str)++;
		return (check_flags(str, elem));
	}
	else
		return (*str);
}

char	*check_width(char **str, t_printf *elem)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!str || !elem)
		return (NULL);
	if ((**str < 48) || (**str > 57))
		return (*str);
	tmp2 = *str;
	while ((*tmp2 >= 48) && (*tmp2 <= 57))
		tmp2++;
	tmp = (char*)malloc(sizeof(char) * ((tmp2 - *str) + 1));
	i = -1;
	while ((**str >= 48) && (**str <= 57))
	{
		tmp[++i] = **str;
		(*str)++;
	}
	tmp[++i] = '\0';
	elem->width = ft_atoi(tmp);
	free(tmp);
	return (*str);
}

char	*check_precision(char **str, t_printf *elem)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (**str != '.')
		return (*str);
	(*str)++;
	if ((**str < 48) || (**str > 57))
		return (*str);
	tmp2 = *str;
	while ((*tmp2 >= 48) && (*tmp2 <= 57))
		tmp2++;
	tmp = (char*)malloc(sizeof(char) * ((tmp2 - *str) + 1));
	i = -1;
	while ((**str >= 48) && (**str <= 57))
	{
		tmp[++i] = **str;
		(*str)++;
	}
	tmp[++i] = '\0';
	elem->precision = ft_atoi(tmp);
	free(tmp);
	return (*str);
}

char	*check_len(char **str, t_printf *elem)
{
	if (**str == 'h' || **str == 'l' || **str == 'L' || **str == 'q' ||
		**str == 'j' || **str == 'z' || **str == 't')
	{
		if (((**str == 'h') && (**(str + 1) == 'h')) ||
			((**str == 'l') && (**(str + 1) == 'l')))
			elem->length = ft_strnew(3);
		else
			elem->length = ft_strnew(2);
		if (**str == 'h' && **(str + 1) == 'h')
			elem->length = "hh";
		else if (**str == 'l' && **(str + 1) == 'l')
			elem->length = "ll";
		else
			elem->length[0] = **str;
		if (ft_strlen(elem->length) > 1)
			(*str)++;
		(*str)++;
	}
	return (*str);
}

int		check_conv(char **str, t_printf *elem)
{
	if ((**str == 's') || (**str == 'S') || (**str == 'p') || (**str == 'd') ||
		(**str == 'D') || (**str == 'i') || (**str == 'o') || (**str == 'O') ||
		(**str == 'u') || (**str == 'U') || (**str == 'x') || (**str == 'X') ||
		(**str == 'c') || (**str == 'C'))
		{
			elem->conversion = **str;
			(*str)++;
		}
	else
		return (0);
	return (1);
}
