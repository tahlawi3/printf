#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putcharl(char c);
int	ft_puthexl(unsigned long long x, char c);
int	ft_putnbrl(int x);
int	ft_putunbrl(unsigned int x);
int	ft_putptrl(unsigned long long ptr);
int	ft_putstrl(char *str);
#endif
