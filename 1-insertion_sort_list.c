#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *						order.
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	/* Initialize a pointer to the second node in the list */
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *tmp = current;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			/* Swap the pointers to perform the node swap */
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;

			/**
			 * Update the list pointer if the current node becomes the new head
			 * of the list
			 */
			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;

			/* Print the current state of the list after the swap */
			print_list(*list);
		}

		current = current->next;
	}
}
