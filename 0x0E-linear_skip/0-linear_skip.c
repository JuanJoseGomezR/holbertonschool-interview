#include "search.h"

/**
 * linear_skip - skip list
 * @list: list to take value from
 * @value: value to take
 * Return: value & index
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *express = NULL, *last = NULL;

	while (current)
	{
		express = current->express;

		if (!express)
		{
			last = current;
			while (last->next)
				last = last->next;
			printf("Value found between indexes [%ld] and [%ld]\n",
					current->index,
					last->index);
		}
		else
		{
			printf("Value checked at index [%ld] = [%d]\n", express->index, express->n);
			if (value > express->n)
			{
				current = express;
				continue;
			}
			else
				printf("Value found between indexes [%ld] and [%ld]\n",
						current->index,
						express->index);
		}

		while (current)
		{
			printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
			if (value == current->n)
				return (current);

			current = current->next;
		}
	}

	return (NULL);
}
