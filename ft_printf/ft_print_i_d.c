/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:40 by alaakson          #+#    #+#             */
/*   Updated: 2024/05/22 13:18:26 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_len(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static int	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10) == -1)
			return (-1);
		if (ft_putnbr(n % 10) == -1)
			return (-1);
	}
	else
	{
		c = n + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_i_d(int n)
{
	if (ft_putnbr(n) == -1)
		return (-1);
	return (int_len(n));
}
