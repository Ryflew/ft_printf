/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 01:01:28 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/28 01:01:40 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countnbr(int nbr)
{
	int count;

	if (nbr == -2147483648)
		return (11);
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
