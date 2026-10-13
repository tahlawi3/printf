#include "ft_printf.h"

int	ft_putunbrl(unsigned int x)
{
	int		len;
	int		res;
	char	c;

	len = 0;
	if (x >= 10)
	{
		res = ft_putunbrl(x / 10);
		if (res == -1)
			return (-1);
		len += res;
		res = ft_putunbrl(x % 10);
		if (res == -1)
			return (-1);
		len += res;
	}
	else
	{
		c = x + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}
