/*
** put_nbr_str
** File description:
** put a int given as argument into a string that will be returned
*/

#include "../include/my.h"

int get_exposant_nbr(int nbr)
{
    int exposant = 0;

    if (nbr < 0)
        nbr = nbr * (-1);
    while (raising(10, exposant) <= nbr)
        exposant++;
    if (exposant == 0)
        exposant = 1;
    return (exposant);
}

int get_size_str(int nbr, int exposant)
{
    if (nbr < 0)
        exposant++;
    exposant += 3;
    return (exposant);
}

void prepare_str_neg_case(char *str, int *nbr, int *i)
{
    if (*nbr < 0) {
        str[0] = '-';
        *i = 1;
        *nbr = *nbr * (-1);
    }
}

char *put_nbr_str(int nbr)
{
    int exposant = (get_exposant_nbr(nbr) - 1);
    int size = get_size_str(nbr, exposant);
    char *str = (char *)malloc(sizeof(char) * size);
    int i = 0;
    int count = raising(10, exposant);

    prepare_str_neg_case(str, &nbr, &i);
    while (count > 0) {
        str[i] = 48 + (nbr / count);
        nbr = nbr % count;
        count /= 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}
