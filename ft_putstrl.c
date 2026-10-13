#include "ft_printf.h"

int	ft_putstrl(char *str)
{
	int	i;
	int	res;

	if (str == 0)
	{
		res = write(1, "(null)", 6);
		if (res == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		res = write(1, &str[i], 1);
		if (res == -1)
			return (-1);
		i++;
	}
	return (i);
}
