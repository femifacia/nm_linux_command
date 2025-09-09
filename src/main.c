
#include "../include/my.h"

bool check_buff(void *buff)
{
    char *str = NULL;
    Elf64_Ehdr *elf = NULL;

    if (buff == MAP_FAILED)
        return (1);
    str = (char *)buff;
    if (str[0] != ELFMAG0)
        return (1);
    if (str[1] != ELFMAG1)
        return (1);
    if (str[2] != ELFMAG2)
        return (1);
    if (str[3] != ELFMAG3)
        return (1);
    elf = (Elf64_Ehdr *)buff;
    if (elf->e_type == ET_CORE)
        return (1);
    return (0);
}

int print_title(char *path, bool state, Elf64_Ehdr *elf, Elf64_Shdr *section)
{
    struct stat info;
    void *buff = NULL;
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        printf("nm: '%s': No such file\n", path);
        return (84);
    }
    fstat(fd, &info);
    buff = mmap(NULL, info.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (check_buff(buff)) {
        printf("nm: %s: file format not recognized\n", path);
        close(fd);
        return (84);
    }
    if (state)
        printf("\n%s:\n", path);
    close(fd);
    return (0);
}

void active_nm(int ac, char **argv, int *ret)
{
    for (int i = 1; i < ac; i++) {
        if (print_title(argv[i], 1, NULL, NULL))
            *ret = 84;
        else
            nm_file(argv[i]);
    }
}

int launch_nm(char **argv, int ac)
{
    int ret = 0;

    if (ac == 2) {
        if (print_title(argv[1], 0, NULL, NULL))
            ret = 84;
        else
            nm_file(argv[1]);
    } else
        active_nm(ac, argv, &ret);
    return (ret);
}

int main(int argc, char **argv)
{
    char *al[3] = {argv[0], "a.out", NULL};

    if (argc < 2)
        return (launch_nm(al, 2));
    return (launch_nm(argv, argc));
}