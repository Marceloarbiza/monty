#include "monty.h"

int main(void)
{
    stack_t *head;

    head = NULL;
    _push(&head, 1);
    _push(&head, 2);
    _push(&head, 3);
    _push(&head, 4);
    _push(&head, 5);
    _push(&head, 6);
    _push(&head, 7);
    _add(&head);
    _swap(&head);
    _pop(&head);
    _pall(head);
    printf("PINT:");
    _pint(&head);
    _pop(&head);
    _pall(head);
    printf("PINT:");
    _pint(&head);
    return (EXIT_SUCCESS);
}
