#include "lists.h"

/**
 * listint_len - Retunr elements count in the linked list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
	int count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}
