/*
** is_list_sorted
** File description:
** return 1 if the list of word is sorted otherwise 0
*/

#include "../include/my.h"

bool is_list_sorted(t_control *control)
{
    t_element *element = control->head;

    while (element) {
        if (!is_sorted(element))
            return (0);
        element = element->next;
    }
    return (1);
}
