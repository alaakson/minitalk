/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:08:19 by alaakson          #+#    #+#             */
/*   Updated: 2024/05/22 13:20:34 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (format == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (format == 'd' || format == 'i')
		return (ft_print_i_d((va_arg(args, int))));
	else if (format == 'X' || format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'p')
		return (ft_print_p(va_arg(args, void *)));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				len;
	unsigned int	i;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			len += ft_format(args, str[++i]);
			if (len == -1)
				return (-1);
		}
		else
		{
			len += ft_putchar(str[i]);
			if (len == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
