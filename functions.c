#include "monty.h"

void add(stack_t **head)
{
	size_t lenh = dlistint_len(*head);

	if (lenh < 2)
	{
		printf("L<line_number>: can't add, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		(*head)->next->n += (*head)->n;
		delete_dnodeint_at_index(head, 0);
	}
}


