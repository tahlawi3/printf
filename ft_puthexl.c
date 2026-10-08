#include "ft_printf.h"

int	ft_puthexl(unsigned long long x, char c)
{
	int		len;
	char	*base;

	len = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (x >= 16)
	{
		len += ft_puthexl(x / 16, c);
		len += ft_puthexl(x % 16, c);
	}
	else
	{
		write(1, &base[x], 1);
		len++;
	}
	return (len);
}
