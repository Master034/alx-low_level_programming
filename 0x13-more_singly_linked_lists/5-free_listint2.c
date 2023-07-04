#include "lists.h"
/**
 * free_listint2 - free the linked list
 * @head : pointer to list
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *node;

	if (!head)
		return;
	while (*head)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
	}
	head = NULL;
}
