#include "ft_printf.h"

int	ft_putcharl(char c)
{
	int	res;

	res = write(1, &c, 1);
	if (res == -1)
		return (-1);
	return (1);
}
