/*
** my_strlen
** File description:
** return number of character in a string
*/

int my_strlen(char const *str)
{
    int size = 0;

    while (*str != '\0') {
        size++;
        str++;
    }
    return (size);
}
