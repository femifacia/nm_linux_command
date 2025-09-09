/*
** my_strdup
** File description:
** return a heap allocated char *
*/

#include "../include/my.h"

char *my_strdup(char *str)
{
    int size = my_strlen(str);
    char *new_str = (char *)malloc(sizeof(char) * (size + 1));

    for (int i = 0; str[i]; i++) {
        new_str[i] = str[i];
    }
    new_str[size] = '\0';
    return (new_str);
}
