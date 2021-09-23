/**
 * add_node_end - Add a node to the end of the queue
 * @stack: The stack
 * @argument: The argument to add
 */
void add_node_end(stack_t **stack, int argument)
{
        stack_t *last = *stack;
        stack_t *new;

        new = malloc(sizeof(stack_t));
        if (!new)
        {
                dprintf(STDERR_FILENO, "Error: malloc failed\n");
                free_all(stack);
                exit(EXIT_FAILURE);
        }
        new->n = argument;
        new->next = NULL;

        if (*stack == NULL)
        {
                new->prev = NULL;
                *stack = new;
                return;
        }

        while (last->next)
                last = last->next;
        last->next = new;
        new->prev = last;
}
