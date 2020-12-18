#include "lists.h"

/**
 * insert_node - inserts a number in a sorted sllist
 * @head: first node
 * @number: number to insert in the llist
 * Return: new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL || number < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	for (tmp = *head; tmp->next != NULL; tmp = tmp->next)
	{
		if (number >= tmp->n && number < tmp->next->n)
		{
			new->next = tmp->next;
			tmp->next = new;
			return (new);
		}
	}
	tmp->next = new;
	new->next = NULL;
	return (new);
}
