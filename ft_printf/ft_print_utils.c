/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:11:28 by alaakson          #+#    #+#             */
/*   Updated: 2024/05/22 13:20:25 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_por(void)
{
	write (1, "%", 1);
	return (1);
}

int	ft_putchar(char c)
{
	if (write (1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(const char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			str;

	str = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == str)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == str)
		return ((char *) &s[i]);
	return (NULL);
}
