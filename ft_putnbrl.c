#include "ft_printf.h"

int	ft_putnbrl(int x)
{
	int		len;
	char	c;

	len = 0;
	if (x == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (x < 0)
	{
		len += write (1, "-", 1);
		x *= -1;
	}
	if (x >= 10)
	{
		len += ft_putnbrl(x / 10);
		len += ft_putnbrl(x % 10);
	}
	else
	{
		c = x + '0';
		len += write(1, &c, 1);
	}
	return (len);
}
