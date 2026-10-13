#include "ft_printf.h"

int	ft_putptrl(unsigned long long ptr)
{
	int	len;
	int	res;

	if (ptr == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	res = ft_puthexl(ptr, 'x');
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}
