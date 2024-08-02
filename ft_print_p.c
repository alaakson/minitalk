/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:01:08 by alaakson          #+#    #+#             */
/*   Updated: 2024/05/22 13:28:26 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	point_len(unsigned long ptr)
{
	unsigned int	len;

	if (ptr == 0)
		return (1);
	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static int	ft_put_point(unsigned long num)
{
	if (num >= 16)
	{
		if (ft_put_point(num / 16) == -1)
			return (-1);
		if (ft_put_point(num % 16) == -1)
			return (-1);
	}
	else
	{
		if (num <= 9)
			ft_putchar (num + '0');
		else
			ft_putchar (num - 10 + 'a');
	}
	return (1);
}

int	ft_print_p(void *ptr)
{
	unsigned long	tmp;
	int				len;

	len = 0;
	tmp = (unsigned long)ptr;
	if (write (1, "0x", 2) != 2)
		return (-1);
	len += 2;
	if (tmp == 0)
	{
		if (write (1, "0", 1) != 1)
			return (-1);
		return (len + 1);
	}
	if (ft_put_point(tmp) == -1)
		return (-1);
	return (len + point_len(tmp));
}
