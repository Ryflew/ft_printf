/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:55:15 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/28 01:43:17 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <wchar.h>

typedef struct		s_printf
{
	char			flag_sharp;
	char			flag_zero;
	char			flag_minus;
	char			flag_plus;
	char			flag_space;
	int				width;
	int				precision;
	char			*length;
	char			conversion;
}					t_printf;

int					ft_printf(const char * restrict format, ...);
int					treat(t_printf *elem, va_list ap);
int					ft_c(char c, t_printf *elem);
//int					ft_s(wchar_t str, t_printf *elem);
int					ft_d(int nbr, t_printf *elem);
int					check_conv(char **str, t_printf *elem);
char				*check_flags(char **str, t_printf *elem);
char				*check_width(char **str, t_printf *elem);
char				*check_precision(char **str, t_printf *elem);
char				*check_len(char **str, t_printf *elem);
void				ft_putnbrwp(int nbr, int precision);

#endif