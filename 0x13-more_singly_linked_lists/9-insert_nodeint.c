#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node in a linked list at a position.
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert.
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int p;
	listint_t *new;
	listint_t *node = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (p = 0; node && p < idx; p++)
	{
		if (p == idx - 1)
		{
			new->next = node->next;
			node->next = new;
			return (new);
		}
		else
			node = node->next;
	}

	return (NULL);
}
