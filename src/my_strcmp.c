/*
** my_strcmp
** File description:
** return 1 if the two string are same else 0
*/

#include "../include/my.h"

bool my_strcmp(char *str1, char *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);

    if (size1 != size2)
        return (0);
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}
