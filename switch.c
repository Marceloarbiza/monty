#include "monty.h"

/**
 *
 *
 *
 *
 */
void switch_s(stack_t **st, char *s, int lnum)(stack_t **, unsigned int)
{
	instruction_t swi[] = {
		{"add", _add}, {"sub", _sub}, {"div", _div}, {"mul", _mul},
		{"mod", _mod}, {"swap", _swap}, {"pop", _pop}, {"pint", _pint}
	};

	int a;
	unsigned int b;

	a = 0;

	while (swi[a].opcode)
	{
		for (b = 0; b < strlen(s); b++)
			if {s[b] = '\0'};

		if (strcmp(swi[a].opcode, s) == 0)
			return (swi[a].f);
		a++;
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lnum, s);
	free_all(st);
	exit(EXIT_FAILURE);
