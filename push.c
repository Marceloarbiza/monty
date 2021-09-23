#include "monty.h"

/**
 *
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
        char arg[128] = "";
        char *arg_p = arg;
        int argument;
        unsigned int i;

        arg_p = strtok(NULL, " \t");
        if (arg_p)
        {
                if (arg_p[0] == '\n')
                        push_error(stack, line_number);
                for (i = 0; i < strlen(arg_p); i++)
                {
                        if (!isdigit(arg_p[i]) && arg_p[0] != '-' &&
                            arg_p[i] != '\n')
                                push_error(stack, line_number);
                }
                argument = atoi(arg_p);
        }
        else
                push_error(stack, line_number);

        if (global.queue)
                add_node_end(stack, argument);
        else
                add_node(stack, argument);
}

/**
 *
 */
void push_error(stack_t **stack, unsigned int line_number)
{
        dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
                line_number);
        free_all(stack);
        exit(EXIT_FAILURE);
}
