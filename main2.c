#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_printf.h"

int main(void)
{
    int ret_ft;
    int saved_stdout;

    // Save stdout so we can print to the terminal later
    saved_stdout = dup(1);

    // Close stdout
    close(1);

    // This should fail and return -1
    ret_ft = ft_printf("%d%d",42,32);

    // Restore stdout temporarily so we can print the result
    dup2(saved_stdout, 1);
    close(saved_stdout);

    // Now this will successfully print to your terminal
    printf("Return value: %d\n", ret_ft); 
    
    return (0);
}