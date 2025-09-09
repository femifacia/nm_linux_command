/*
** my_put_nbr
** File description:
** a remake
*/

#include "../include/my.h"

int negatif_seeker(int nbr)
{
    if (nbr < 0)
        return (-1 * (nbr));
    else
        return (nbr);
}

int counter_digits(int nbr)
{
    int count = 10;
    int a = 1;

    while ((nbr / count) > 0)
    {
        a++;
        count *= 10;
    }
    return a;
}

void my_put_nbr(int nbr)
{
    int nbr_digits = (counter_digits(negatif_seeker(nbr)));
    int count = 1;
    int a = 0;
    int nbr_clone = (negatif_seeker(nbr));

    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    for (int i = 1; i < nbr_digits; i++)
        count *= 10;
    for (int i = 0; i < nbr_digits; i++ ) {
        a = nbr_clone / count;
        my_putchar(a + 48);
        nbr_clone %= count;
        count /= 10;
    }
}
