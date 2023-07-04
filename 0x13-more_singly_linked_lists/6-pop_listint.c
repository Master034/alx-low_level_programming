#include "lists.h"
/**
 * pop_listint - deletes the head node
 * @head : pointer to the head
 * Return: head node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *node;
	int n;
	
	node = *head;
	if (node == NULL)
		return (0);
	*head = node->next;
	n = node->n;
	free(node);
	return (n);
}
