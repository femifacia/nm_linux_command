/*
** my_getnbr
** File description:
** convert a number inside a char * to an int
*/

#include "../include/my.h"

int is_a_number(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    else
        return (0);
}

int char_before_numb(char const *str)
{
    int number = 0;
    int a = 0;
    int i = is_a_number(str[a]);

    while (str[a] == 43 || str[a] == 45) {
        if (str[a] == 43 || str[a] == 45)
            number++;
        a++;
    }
    return (number);
}

int signe(int a, char const *str)
{
    int count = (a - 1);
    int b = 0;
    int sign = 1;

    for (int i = 0; i <= (a - 1); i++) {
        if (str[i] == 45)
            sign = -sign;
    }

    return (sign);
}

int my_strlen_number(char const *str)
{
    int number = 0;

    while (*str != '\0' && (is_a_number(*str)) == 1)
    {
        str++;
        number++;
    }
    return (number);
}

int my_getnbr(char const *str)
{
    int barrage = char_before_numb(str);
    int size = my_strlen_number(&str[barrage]);
    int i = barrage;
    int number = 0;
    int a = 0;
    int b = size - 1;
    int sign = signe(barrage, &str[0]);

    while (i < (size + barrage))
    {
        a = (str[i] - 48);
        number += (a * (raising(10, (b))));
        i++;
        b --;
    }
    number = number * sign;
    return (number);
}
