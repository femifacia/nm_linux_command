/*
** my_array_len
** File description:
** return the size of a array
*/

#include "../include/my.h"

int my_array_len(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        i++;
    }
    return (i);
}
