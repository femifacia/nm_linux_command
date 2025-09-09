/*
** structure.h
** File description:
** the header file that countains structure and typedef
*/

#ifndef CHECK_STRUCT
#define CHECK_STRUCT 5

typedef struct t_element {
    char *word;
    uint32_t addr;
    char type;
    struct t_element *next;
    struct t_element *prev;
}t_element;

typedef struct t_control {
    t_element *head;
    t_element *tail;
}t_control;
#endif
