#include "monty.h"

/**
 * add_dnodeint - add node beginning
 * @head: head
 * @n: int
 * Return: struct
 */
stack_t *_push(stack_t **head, const int n)
{
	stack_t *new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}
	else
	{
		new->n = n;
		new->next = *head;
		new->prev = NULL;
		if (*head)
		{
			(*head)->prev = new;
		}
			*head = new;
	}
	return (new);
}

/**
  * print_dlistint - print double linked list
  * @h: head list
  * Return: size_t
  */
size_t _pall(const stack_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}

void _add(stack_t **head)
{
	size_t lenh = dlistint_len(*head);

	if (lenh < 2)
	{
		fprintf(stderr, "L<line_number>: can't add, stack too short\n");
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
		fprintf(stderr, "L<line_number>: can't swap, stack too short\n");
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
		fprintf(stderr, "L<line_number>: can't pop, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head)
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
		fprintf(stderr, "L<line_number>: can't pint, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		npint = (*head)->n;
		printf("%d\n", npint);
	}
}


void _sub(stack_t **head)
{
	size_t lenh = dlistint_len(*head);

	if (lenh < 2)
	{
		fprintf(stderr, "L<line_number>: can't sub, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		(*head)->next->n -= (*head)->n;
		delete_dnodeint_at_index(head, 0);
	}
}

void _div(stack_t **head)
{
	size_t lenh = dlistint_len(*head);

	if (lenh < 2)
	{
		fprintf(stderr, "L<line_number>: can't div, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L<line_number>: division by zero\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		(*head)->next->n /= (*head)->n;
		delete_dnodeint_at_index(head, 0);
	}
}

void _mul(stack_t **head)
{
	size_t lenh = dlistint_len(*head);

	if (lenh < 2)
	{
		fprintf(stderr, "L<line_number>: can't mul, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		(*head)->next->n *= (*head)->n;
		delete_dnodeint_at_index(head, 0);
	}
}

void _mod(stack_t **head)
{
	size_t lenh = dlistint_len(*head);

	if (lenh < 2)
	{
		fprintf(stderr, "L<line_number>: can't mod, stack too short\n");
		exit (EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L<line_number>: division by zero\n");
		exit (EXIT_FAILURE);
	}

	if (*head && (*head)->next)
	{
		(*head)->next->n %= (*head)->n;
		delete_dnodeint_at_index(head, 0);
	}
}

void _pchar(stack_t **head)
{
	size_t lenh = dlistint_len(*head);
	char c;

	if (lenh == 0)
	{
		fprintf(stderr, "L<line_number>: can't pchar, stack empty\n");
		exit (EXIT_FAILURE);
	}

	if ((*head)->n > 255 || (*head)->n < 33)
	{
		fprintf(stderr, "L<line_number>: can't pchar, value out of range\n");
		exit (EXIT_FAILURE);
	}

	if (*head)
	{
		c = (*head)->n;
		printf("%c\n", c);
	}
}

void _pstr(stack_t **head)
{
	size_t lenh = dlistint_len(*head);
	char c;

	while (*head)
	{
		if ((*head)->n == 0)
		{
			break;
		}

		if ((*head)->n > 255 || (*head)->n < 33)
		{
			break;
		}

		c = (*head)->n;
		printf("%c", c);

		(*head) = (*head)->next;
	}
	printf("\n");
}

void _rotr(stack_t **head)
{
	int ntmp = 0, ftmp = 0;
	stack_t *tmp = *head;
	
	if (*head)
	{
		ntmp = (*head)->n;

		while (tmp->next)
		{
			tmp = tmp->next;
		}

		ftmp = tmp->n;
		tmp->n = ntmp;
		(*head)->n = ftmp;
	}
}

void _rotl(stack_t **head)
{
	int ntmp = 0;
	stack_t *tmp = *head;

	if (*head)
	{
		ntmp = (*head)->n;

		while (tmp->next)
		{
			tmp = tmp->next;
			tmp->prev->n = tmp->n;
		}

		tmp->n = ntmp;
	}
}
