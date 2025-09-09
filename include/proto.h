/*
** proto.h
** File description:
** the header file that countains function's prototype
*/

#ifndef CHECK_PROTO
    #define CHECK_PROTO 5
#include "libra.h"
#include "structure.h"
void sort_word(t_control *control);
bool is_sorted(t_element *element);
bool is_list_sorted(t_control *control);
void print_list(t_control *control);
void add_elm_list(t_control *control, t_element *elem);
t_element *create_elm(Elf64_Sym *s, char *st, int i, Elf64_Ehdr *elf);
int get_size_file(char *path);
void my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
void my_put_nbr(int nbr);
int my_getnbr(char const *str);
int raising(int nbr, int n);
char *put_nbr_str(int nbr);
int my_array_len(char **array);
bool my_strcmp(char *str1, char *str2);
char *my_strdup(char *str);
char *my_strconcat(char *str1, char *str2);
char *get_file_content(char *path);
int count_char(char *str, char c);
void free_array(void **array);
char *my_strdup_char(char *str, char c);
char **cut_str_array(char *str, char c);
int nm_file(char *path);
void free_control(t_control *control);
#endif
