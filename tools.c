#include "monty.h"

/**
 * dlistint_len - count elements
 * @h: head list
 * Return: size_t
 */
size_t dlistint_len(const stack_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}

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
