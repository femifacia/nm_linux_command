/*
** my_putchar
** File description:
** print one char
*/
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
