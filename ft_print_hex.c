/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:53:20 by alaakson          #+#    #+#             */
/*   Updated: 2024/05/22 13:11:30 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int value)
{
	int	len;

	if (value == 0)
		return (1);
	len = 0;
	while (value != 0)
	{
		len++;
		value = value / 16;
	}
	return (len);
}

static int	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		if (ft_put_hex (num / 16, format) == -1)
			return (-1);
		if (ft_put_hex (num % 16, format) == -1)
			return (-1);
	}
	else
	{
		if (num <= 9)
			return (ft_putchar(num + '0'));
		else
		{
			if (format == 'x')
				return (ft_putchar (num - 10 + 'a'));
			if (format == 'X')
				return (ft_putchar(num - 10 + 'A'));
		}
	}
	return (1);
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	if (ft_put_hex(num, format) == -1)
		return (-1);
	return (hex_len(num));
}
