/*
** is_sorted
** File description:
** return (1) if the element of the list and his next are classed
*/

#include "../include/my.h"

int char_classed(char a, char b)
{
    if (a >= 'a' && a <= 'z')
        if (b >= 'A' && b <= 'Z')
            a -= 32;
    if (b >= 'a' && b <= 'z')
        if (a >= 'A' && a <= 'Z')
            b -= 32;
    if (a < b)
        return (1);
    if (a > b)
        return (0);
    if (a == b)
        return (2);
}

bool cmp_underscore(char *str1, char *str2, int i, int j)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);

    if (!str1[i] && !str2[j]) {
        if (size1 > size2)
            return (1);
        return (0);
    }
    if (!str1[i])
        return (1);
    return (0);
}

bool str_classed(char *str1, char *str2, int i, int j)
{
    int result = 0;
    int a = 0;
    int b = 0;

    while (str1[i] && str2[j]) {
        while (str1[i] == '_')
            i++;
        while (str2[j] == '_')
            j++;
        result = char_classed(str1[i], str2[j]);
        if (result == 1)
            return (1);
        if (result == 0)
            return (0);
        if (result == 2) {
            i++;
            j++;
        }
    }
    return (cmp_underscore(str1, str2, i, j));
}

bool is_sorted(t_element *element)
{
    t_element *element_next = element->next;
    char *str1 = element->word;
    char *str2 = NULL;

    if (!element_next)
        return (1);
    str2 = element_next->word;
    if (str_classed(str1, str2, 0, 0))
        return (1);
    return (0);
}
