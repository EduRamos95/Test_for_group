#include "sort.h"

/**
 * swap_dll - Swap two elements in a double linked list
 * @hi: The higher element
 * @lo: The lower element
 */
void swap_dll(listint_t *hi, listint_t *lo)
{
	hi->next = lo->next;

	if (hi->prev)
		hi->prev->next = lo;
	if (lo->next)
		lo->next->prev = hi;

	lo->next = hi;
	lo->prev = hi->prev;
	hi->prev = lo;
}

/**
 * insertion_sort_list - Implement insertion sort algorithm
 * @list: The list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *tmp2 = NULL;

	/* check if the argument passed and address of list exist */
	if (list == NULL)
		return;

	/* iterate in the list only if it exists */
	for (tmp = *list; tmp; tmp = tmp->next)
	{
		tmp2 = tmp;

		/* swap while there are a high and and low elements */
		while (tmp2->prev && (tmp2->n < tmp2->prev->n))
		{
			swap_dll(tmp2->prev, tmp2);

			/**
			 * if there is not more swapable elements and if the node
			 * is the new head of the list.
			 * set the partial list to **list
			 */
			if (!tmp2->prev)
				*list = tmp2;

			print_list(*list);
		}
	}
}
