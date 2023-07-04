#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of freed elements.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int diff;
	listint_t *node;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			node = (*h)->next;
			free(*h);
			*h = node;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}

	*h = NULL;

	return (count);
}
