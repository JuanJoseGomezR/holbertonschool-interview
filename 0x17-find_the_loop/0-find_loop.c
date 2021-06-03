#include "lists.h"

/**
  * find_listint_loop - find loop in linkedlist
  * @head: head node (first node)
  * Return: node where loop starts
  */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a = head;
	listint_t *b = head;

	while (a && b && b->next)
	{
		a = a->next;
		b = b->next->next;

		if (a == b)
		{
			return (a);
		}
	}
	return (NULL);
}
