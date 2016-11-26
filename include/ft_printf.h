/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:55:15 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/26 01:49:58 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_printf
{
	char		flag_sharp;
	char		flag_zero;
	char		flag_minus;
	char		flag_plus;
	char		flag_space;
	int			width;
	int			precision;
}				t_printf;

int				ft_printf(const char * restrict format, ...);
char			*check_flags(char *str, t_printf *elem);
char			*check_width(char *str, t_printf *elem);
char			*check_precision(char *str, t_printf *elem);
char			*check_len(char *str, t_printf *elem);
int				ft_s(char *str);
int				ft_d(int nbr);
int				ft_c(int c);
int				ft_percent();

#endif