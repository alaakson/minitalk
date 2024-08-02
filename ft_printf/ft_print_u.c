/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:00:10 by alaakson          #+#    #+#             */
/*   Updated: 2024/05/22 13:14:05 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putnbr_ulong(unsigned long n)
{
	if (n >= 10)
	{
		if (ft_putnbr_ulong(n / 10) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (0);
}

static int	get_len(unsigned int value)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		len++;
		value = value / 10;
	}
	return (len);
}

int	ft_print_u(unsigned long int num)
{
	int	len;

	len = get_len(num);
	if (ft_putnbr_ulong(num) == -1)
		return (-1);
	return (len);
}
