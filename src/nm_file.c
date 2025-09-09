/*
** File description:
** nm_file
*/

#include "../include/my.h"

char *fill_tab(char *ph, Elf64_Sym **sym, Elf64_Shdr **symtab, Elf64_Ehdr **elf)
{
    struct stat info;
    int fd = open(ph, O_RDONLY);
    void *buff = NULL;
    Elf64_Shdr *strtab_elf = NULL;
    Elf64_Shdr *section;

    fstat(fd, &info);
    buff = mmap(NULL, info.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    *elf = (Elf64_Ehdr *)buff;
    section = (void *)*elf + (*elf)->e_shoff;
    char *section_names = (void *)*elf + section[(*elf)->e_shstrndx].sh_offset;
    for (int i = 0; i < (*elf)->e_shnum; i++) {
        if (!strcmp(".symtab", section_names + section[i].sh_name)) {
            *symtab = (Elf64_Shdr *)&section[i];
        } else if (!strcmp(".strtab", section_names + section[i].sh_name))
            strtab_elf = &(section[i]);
    }
    char *strtab = (void *)*elf + strtab_elf->sh_offset;
    *sym = (Elf64_Sym *)((void *)*elf + (*symtab)->sh_offset);
    close(fd);
    return (strtab);
}

int nm_file(char *path)
{
    Elf64_Ehdr *elf;
    Elf64_Shdr *symtab = NULL;
    Elf64_Sym *sym = NULL;
    char *strtab = fill_tab(path, &sym, &symtab, &elf);
    t_control *control = (t_control *)malloc(sizeof(t_control));
    t_element *tmp = NULL;

    control->head = NULL;
    control->tail = NULL;
    for (int i = 0; i < (symtab->sh_size / sizeof(Elf64_Sym)); i++) {
        tmp = create_elm(sym, strtab, i, elf);
        if (tmp)
            add_elm_list(control, tmp);
    }
    sort_word(control);
    print_list(control);
    free_control(control);
    return (0);
}