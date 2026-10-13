#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int     ft_len;
    int     og_len;
    char    *null_str;

    null_str = NULL;

    printf("=== TESTING FT_PRINTF ===\n\n");

    // 1. Character & String
    ft_len = ft_printf("FT: Char: %c, String: %s\n", 'A', "Hello 42");
    og_len = printf("OG: Char: %c, String: %s\n", 'A', "Hello 42");
    printf("Lengths -> FT: %d | OG: %d\n\n", ft_len, og_len);

    // 2. NULL String
    ft_len = ft_printf("FT: Null string: %s\n", null_str);
    og_len = printf("OG: Null string: %s\n", null_str);
    printf("Lengths -> FT: %d | OG: %d\n\n", ft_len, og_len);

    // 3. Integers & INT_MIN
    ft_len = ft_printf("FT: Int: %d, INT_MIN: %d\n", 42, INT_MIN);
    og_len = printf("OG: Int: %d, INT_MIN: %d\n", 42, INT_MIN);
    printf("Lengths -> FT: %d | OG: %d\n\n", ft_len, og_len);

    // 4. Unsigned Int
    ft_len = ft_printf("FT: Unsigned: %u\n", 4294967295U);
    og_len = printf("OG: Unsigned: %u\n", 4294967295U);
    printf("Lengths -> FT: %d | OG: %d\n\n", ft_len, og_len);

    // 5. Hexadecimal (x / X)
    ft_len = ft_printf("FT: Hex: %x, HEX: %X\n", 255, 255);
    og_len = printf("OG: Hex: %x, HEX: %X\n", 255, 255);
    printf("Lengths -> FT: %d | OG: %d\n\n", ft_len, og_len);

    // 6. Pointer & NULL Pointer
    int a = 42;
    ft_len = ft_printf("FT: Pointer: %p, Null Ptr: %p\n", (void *)&a, NULL);
    og_len = printf("OG: Pointer: %p, Null Ptr: %p\n", (void *)&a, NULL);
    printf("Lengths -> FT: %d | OG: %d\n\n", ft_len, og_len);

    // 7. Percent sign
    ft_len = ft_printf("FT: Percent: %%\n");
    og_len = printf("OG: Percent: %%\n");
    printf("Lengths -> FT: %d | OG: %d\n", ft_len, og_len);

    return (0);
}
