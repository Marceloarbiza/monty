#include "monty.h"

/**
 *
 *
 */
void add_node(stack_t **stack, int argument)
{
        stack_t *new;

        new = malloc(sizeof(stack_t));
        if (!new)
        {
                dprintf(STDERR_FILENO, "Error: malloc failed\n");
                free_all(stack);
                exit(EXIT_FAILURE);
        }
        new->n = argument;
        new->next = *stack;
        new->prev = NULL;
        if (*stack)
                (*stack)->prev = new;
        *stack = new;
}
