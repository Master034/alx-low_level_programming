#include "lists.h"
/**
 * list_len - returns elements count in a list.
 * @h: singly linked list.
 * Return: number of elements in the list.
 */

size_t list_len(const list_t *h)
{
	size_t c_nodes;

	c_nodes = 0;
	while (h != NULL)
	{
		h = h->next;
		c_nodes++;
	}
	return (c_nodes);
}
