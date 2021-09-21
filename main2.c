#include "monty.h"

int main(void)
{
    stack_t *head;

    head = NULL;
    add_dnodeint(&head, 1);
    add_dnodeint(&head, 2);
    add_dnodeint(&head, 3);
    add_dnodeint(&head, 4);
    add_dnodeint(&head, 5);
    add_dnodeint(&head, 6);
    add_dnodeint(&head, 7);
    add(&head);
    print_dlistint(head);
    return (EXIT_SUCCESS);
}
