#include "ft_printf.h"

int	ft_putstrl(char *str)
{
	int	i;

	if (str == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
