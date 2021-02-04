#include "lists.h"

/**
* check_cycle - checks if circular linked list
* @list: linked list
* Return: 1 if cycle || 0 if not
*/

int check_cycle(listint_t *list)
{
	listint_t *p = list;
	listint_t *q = list;

	while (p && q && q->next)
	{
		p = p->next;
		q = q->next->next;

		if (p == q)
		{
			return (1);
		}
	}
	return (0);
}

