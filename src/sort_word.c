/*
** sort_word
** File description:
** sort and print words
*/

#include "../include/my.h"

void adjust_head(t_element *w, t_element *x, t_element *y, t_control *control)
{
    if (control->head == x)
        control->head = y;
}

void adjust_tail(t_element *z, t_element *x, t_element *y, t_control *control)
{
    if (control->tail == y)
        control->tail = y;
}

void swap(t_element *element, t_control *control)
{
    t_element *x = element;
    t_element *y = element->next;
    t_element *w = x->prev;
    t_element *z = y->next;

    x->next = z;
    x->prev = y;
    y->next = x;
    y->prev = w;
    if (w)
        w->next = y;
    if (z)
        z->prev = x;
    adjust_head(w, x, y, control);
    adjust_tail(z, x, y, control);
}

void sort_word(t_control *control)
{
    t_element *element = control->head;

    while (!is_list_sorted(control)) {
        if (!is_sorted(element))
            swap(element, control);
        element = element->next;
        if (!element)
            element = control->head;
        if (!element->next)
            element = control->head;
    }
}
