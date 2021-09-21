#include "monty.h"

void _add(stack_t **head)
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

void _swap(stack_t **head)
{
	size_t lenh = dlistint_len(*head);
	int ntmp = 0;

	if (lenh < 2)
	{
		printf("L<line_number>: can't swap, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		ntmp = (*head)->next->n;
		(*head)->next->n += (*head)->n;
		(*head)->n = ntmp;
	}
}

void _pop(stack_t **head)
{
	size_t lenh = dlistint_len(*head);

	if (lenh == 0)
	{
		printf("L<line_number>: can't pop, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		delete_dnodeint_at_index(head, 0);
	}
}

void _pint(stack_t **head)
{
	size_t lenh = dlistint_len(*head);
	int npint = 0;
	
	if (lenh == 0)
	{
		printf("L<line_number>: can't pint, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		npint = (*head)->n;
		printf("%d\n", npint);
	}
}
