#include "lists.h"

/**
 * add_nodeint - Adds A node at the beginning of a linked list.
 * @head: Pointer to the head of the list.
 * @n:Integer to be used as content.
 * Return: New Node.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new != NULL)
	{
		new->n = n;
		new->next = *head;
	}
	else
		return (NULL);
	if (*head != NULL)
		new->next = *head;
	*head = new;
	return (new);
}
