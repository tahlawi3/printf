#include "ft_printf.h"

int	ft_putptrl(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = write(1, "0x", 2);
	len += ft_puthexl(ptr, 'x');
	return (len);
}
