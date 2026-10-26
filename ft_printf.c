/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahlawi3 <tahlawi3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:49:12 by tahlawi3          #+#    #+#             */
/*   Updated: 2026/10/13 10:22:56 by tahlawi3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_form(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putcharl(va_arg(arg, int));
	else if (c == 's')
		len = ft_putstrl(va_arg(arg, char *));
	else if (c == 'i' || c == 'd')
		len = ft_putnbrl(va_arg(arg, int));
	else if (c == 'u')
		len = ft_putunbrl(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_puthexl(va_arg(arg, unsigned int), c);
	else if (c == 'p')
		len = ft_putptrl((unsigned long long)va_arg(arg, void *));
	else if (c == '%')
		len = ft_putcharl('%');
	else
		len = ft_putcharl(c);
	return (len);
}

static int	ft_print(const char *s, int *i, va_list arg, int *len)
{
	int	res;

	if (s[*i] == '%')
	{
		(*i)++;
		if (!s[*i])
			return (0);
		res = ft_form(s[*i], arg);
	}
	else
		res = ft_putcharl(s[*i]);
	if (res == -1)
		return (-1);
	*len += res;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	if (str == 0)
		return (-1);
	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (ft_print(str, &i, arg, &len) == -1)
		{
			va_end(arg);
			return (-1);
		}
		i++;
	}
	va_end(arg);
	return (len);
}
