#include "lists.h"
/**
 * print_listint_safe - prints a linked list with a loop safely.
 * @head: pointer to head node
 * Return: count
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *node = NULL;
	const listint_t *temp = NULL;
	size_t count = 0;
	size_t new;

	node = head;
	while (node)
	{
		printf("[%p] %d\n", (void *)node, node->n);
		count++;
		node = node->next;
		temp = head;
		new = 0;
		while (new < count)
		{
			if (node == temp)
			{
				printf("-> [%p] %d\n", (void *)node, node->n);
				return (count);
			}
			temp = temp->next;
			new++;
		}
		if (!head)
			exit(98);
	}
	return (count);
}
