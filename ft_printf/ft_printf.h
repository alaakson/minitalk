/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:29:54 by alaakson          #+#    #+#             */
/*   Updated: 2024/05/22 13:21:40 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		ft_print_por(void);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_p(void *ptr);
int		ft_print_u(unsigned long int num);
int		ft_print_i_d(int n);
char	*ft_strchr(const char *s, int c);

#endif 
