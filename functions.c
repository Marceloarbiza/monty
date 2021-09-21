#include "monty.h"

void add(stack_t **head)
{
	stack_t *tmp = NULL;
	
	if (*head && (*head)->next)
	{
		(*head)->next->n += (*head)->n;
		tmp = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(tmp);
	}
}
