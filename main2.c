#include "monty.h"

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *nodo = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (!nodo)
			return (-1);
		nodo = nodo->next;
	}

	if (nodo == *head)
	{
		*head = nodo->next;
		if (*head)
			(*head)->prev = NULL;
	}

	else
	{
		nodo->prev->next = nodo->next;
		if (nodo->next)
			nodo->next->prev = nodo->prev;
	}

	free(nodo);
	return (1);
}

size_t print_dlistint(const stack_t *h)
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

stack_t *add_dnodeint(stack_t **head, const int n)
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

int main(void)
{
    stack_t *head;

    head = NULL;
    add_dnodeint(&head, 1);
    add_dnodeint(&head, 2);
    add_dnodeint(&head, 3);
    add_dnodeint(&head, 4);
    add_dnodeint(&head, 5);
    add_dnodeint(&head, 6);
    add_dnodeint(&head, 7);
    add(&head);
    print_dlistint(head);
    return (EXIT_SUCCESS);
}
