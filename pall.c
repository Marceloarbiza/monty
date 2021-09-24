#include "monty.h"

/**
 * op_pall - ldldlflclsp
 * @stack: llsdlksdlfkñldf
 * @line_number: ñlkdfñalkñalñla
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pp = *stack;
	(void) line_number;

	while (pp)
	{
		printf("%d\n", pp->n);
		pp = pp->next;
	}
}
