#include "lists.h"
#include <string.h>

/**
 * add_node - A function that adds a node to the head of linked list
 * @head: pointer to a list_t pointer
 * @str: string that goes in new node
 * Return: NULL on failure or New node on success
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	int len = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	while (str[len])
		len++;

	new->len = len;
	new->str = strdup(str);
	new->next = *head;
	*head = new;
	return (new);
}
