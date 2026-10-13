#include "ft_printf.h"

int	ft_putnbrl(int x)
{
	long	n;
	int		len;

	n = x;
	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		n *= -1;
	}
	if (n >= 10)
	{
		x = ft_putnbrl(n / 10);
		if (x == -1)
			return (-1);
		len += x;
		n %= 10;
	}
	x = n + '0';
	if (write(1, &x, 1) == -1)
		return (-1);
	return (len + 1);
}
