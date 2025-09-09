/*
** get_file_content
** File description:
** return a char * which is the content of the file of the path
*/

#include "../include/my.h"

char *get_file_content(char *path)
{
    int fd = open(path, O_RDONLY);
    int check = 0;
    char *str = NULL;
    int size = get_size_file(path);

    if (fd == -1)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (size + 1));
    check = read(fd, str, size);
    str[size] = '\0';
    close(fd);
    if (check == -1) {
        free(str);
        return (NULL);
    }
    return (str);
}
