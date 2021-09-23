#include "monty.h"

/**
 * get_opcode - Determine which opcode function to execute
 * @st: The stack
 * @s: The string containing the opcode
 * @lnum: The line number
 *
 * Return: The name of the function to execute
 */
void (*get_opcode(stack_t **st, char *s, int lnum))(stack_t **, unsigned int)
{
        instruction_t ops[] = {
                {"push", _push},
                {"pall", _pall},
                {"pint", _pint},
                {"pop",  _pop},
                {"swap", _swap},
                {"add", _add},
                {"nop", _nop},
                {"sub", _sub},
                {"div", _div},
                {"mul", _mul},
                {"mod", _mod},
                {"pchar", _pchar},
                {"pstr", _pstr},
                {"rotl", _rotl},
                {"rotr", _rotr},
                {"stack", _stack},
                {"queue", _queue},
                {NULL, NULL}
        };
        int i = 0;
        unsigned int j;

        while (ops[i].opcode)
        {
                for (j = 0; j < strlen(s); j++)
                        if (s[j] == '\n')
                                s[j] = '\0';
                if (strcmp(ops[i].opcode, s) == 0)
                        return (ops[i].f);
                i++;
        }

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lnum, s);
        free_all(st);
        exit(EXIT_FAILURE);
}
