/*
** File description:
** manage_control
*/

#include "../include/my.h"

void add_elm_list(t_control *control, t_element *elem)
{
    if (!control->head)
        control->head = elem;
    else {
        if (!control->tail) {
            elem->prev = control->head;
            control->head->next = elem;
        } else {
            elem->prev = control->tail;
            control->tail->next = elem;
        }
        control->tail = elem;
    }
}

void print_list(t_control *control)
{
    for (t_element *elm = control->head; elm; elm = elm->next) {
        if (elm->addr)
            printf("%016x %c %s\n", elm->addr, elm->type, elm->word);
        else {
            printf("                ");
            printf(" %c %s\n", elm->type, elm->word);
        }
    }
}

void fill_sym(t_element *element, Elf64_Sym *sym, int i, Elf64_Ehdr *elf)
{
    Elf64_Shdr *section_e = (void *)elf + elf->e_shoff;
    Elf64_Shdr section = section_e[sym[i].st_shndx];
    char *str = (void *)elf + section_e[elf->e_shstrndx].sh_offset;

    if (ELF64_ST_BIND(sym[i].st_shndx) == SHN_UNDEF)
        element->type = 'u';
    if (ELF64_ST_BIND(sym[i].st_shndx) == SHN_ABS)
        element->type = 'a';
    if (ELF64_ST_BIND(sym[i].st_shndx) == SHN_COMMON)
        element->type = 'c';
    if (section.sh_type == SHT_NOBITS) {
        element->type = 'b';
        if (section.sh_flags == SHF_ALLOC + SHF_WRITE)
            element->type = 'd';
    }
    if (section.sh_type == SHT_PROGBITS) {
        if (section.sh_flags == SHF_ALLOC + SHF_WRITE + SHF_TLS)
            element->type = 'g';
    }
    if (ELF64_ST_TYPE(sym[i].st_info) == STT_GNU_IFUNC)
        element->type = 'i';
    if (section.sh_type == SHT_PROGBITS) {
        if (section.sh_flags == SHF_ALLOC)
            element->type = 'r';
        if (section.sh_flags == SHF_ALLOC + SHF_EXECINSTR)
            element->type = 't';
    }
    if (ELF64_ST_BIND(sym[i].st_info) == STB_WEAK)
        element->type = 'w';
    if (strcmp(str + section.sh_name, ".stab") == 0)
        element->type = '-';
    if (ELF64_ST_BIND(sym[i].st_info) == STB_GLOBAL)
        element->type -= 32;
}

t_element *create_elm(Elf64_Sym *sym, char *strtab, int i, Elf64_Ehdr *elf)
{
    t_element *element = NULL;
    char *str = strtab + sym[i].st_name;

    my_putstr(str);
    my_putchar('\n');
    if (ELF64_ST_TYPE(sym[i].st_info) == STT_FILE)
        return (NULL);
    if (!str || str[0] == '\0')
        return (NULL);
    element = (t_element *)malloc(sizeof(t_element));
    element->next = NULL;
    element->prev = NULL;
    element->addr = sym[i].st_value;
    element->word = strtab + sym[i].st_name;
    element->type = '?';
    fill_sym(element, sym, i, elf);
    return (element);
}

void free_control(t_control *control)
{
    t_element *element = control->head;
    t_element *element_next = ((element) ? element->next : NULL);

    while (element) {
        free(element);
        element = element_next;
        element_next = ((element) ? element->next : NULL);
    }
    free(control);
}