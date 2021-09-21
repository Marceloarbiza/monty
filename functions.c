#include "monty.h"

void add(stack_t **head)
{
	stack_t *tmp = NULL;
	
	size_t lenh = dlistint_len(*head);

	if (lenh < 2)
	{
		printf("L<line_number>: can't add, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		(*head)->next->n += (*head)->n;
		tmp = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(tmp);
	}
}


