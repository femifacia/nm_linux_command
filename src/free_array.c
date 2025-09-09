/*
** free_array
** File description:
** free a char ** array
*/

#include "../include/my.h"

void free_array(void **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
