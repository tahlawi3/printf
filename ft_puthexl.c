#include "ft_printf.h"

static int	ft_putbase(unsigned long long x, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (write(1, &base[x], 1) == -1)
		return (-1);
	return (1);
}

int	ft_puthexl(unsigned long long x, char c)
{
	int		len;
	int		res;

	len = 0;
	if (x >= 16)
	{
		res = ft_puthexl(x / 16, c);
		if (res == -1)
			return (-1);
		len += res;
		res = ft_puthexl(x % 16, c);
		if (res == -1)
			return (-1);
		len += res;
	}
	else
	{
		res = ft_putbase(x, c);
		if (res == -1)
			return (-1);
		len += res;
	}
	return (len);
}
