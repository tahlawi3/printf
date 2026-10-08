#include "ft_printf.h"

int	ft_putunbrl(unsigned int x)
{
	int		len;
	char	c;

	len = 0;
	if (x >= 10)
	{
		len += ft_putunbrl(x / 10);
		len += ft_putunbrl(x % 10);
	}
	else
	{
		c = x + '0';
		write(1, &c, 1);
		len++;
	}
	return (len);
}
