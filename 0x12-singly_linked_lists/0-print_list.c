#include "lists.h"
/**
 * print_list - prints list_t.
 * @h: list.
 * Return: elements count.
 */

size_t print_list(const list_t *h)
{
	size_t n;

	for (n = 0; h != NULL; n++)
	{

		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		n++;

	}
	return (n);
}
