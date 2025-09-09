/*
** get_size_file
** File description:
** return a size of a file
*/

#include "../include/my.h"

int get_size_file(char *path)
{
    int fd = open(path, O_RDONLY);
    char *str = (char *)malloc(sizeof(char));
    int count = 0;
    int byte = 0;

    byte = read(fd, str, 1);
    count++;
    while (byte != 0) {
        byte = read(fd, str, 1);
        count++;
    }
    close(fd);
    free(str);
    if (count == 1)
        count++;
    count -= 2;
    return (count);
}
