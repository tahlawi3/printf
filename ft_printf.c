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
		len = ft_putptrl(va_arg(arg, unsigned long long));
	else if (c == '%')
		len = ft_putcharl('%');
	else
		len = ft_putcharl(c);
	return (len);
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
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			len += ft_form(str[i], arg);
		}
		else
			len += ft_putcharl(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
