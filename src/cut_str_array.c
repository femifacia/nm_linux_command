/*
** cut_str_array
** File description:
** cut an string into a array by a del char
*/

#include "../include/my.h"

char *my_strdup_char(char *str, char c)
{
    int size = 0;
    char *new_str = NULL;

    for (int i = 0; str[i] && str[i] != c; i++)
        size++;
    new_str = (char *)malloc(sizeof(char) * (size + 1));
    for (int i = 0; str[i] && str[i] != c; i++)
        new_str[i] = str[i];
    new_str[size] = '\0';
    return (new_str);
}

char *cut_line(char *str, int posix, char c)
{
    int i = 0;
    int count = 0;
    char *new_str = NULL;

    while (count < posix && str[i]) {
        if (str[i] == c)
            count++;
        i++;
    }
    while (str[i] && str[i] == c)
        i++;
    new_str = my_strdup_char(&str[i], c);
    return (new_str);
}

char **cut_str_array(char *str, char c)
{
    int size = count_char(str, c);
    char **array = NULL;

    if (!size)
        size++;
    size++;
    array = (char **)malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++)
        array[i] = cut_line(str, i, c);
    array[size] = NULL;
    return (array);
}
