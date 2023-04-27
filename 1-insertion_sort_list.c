#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly linked list of integers
 * @list: doubly linked list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *next = NULL;

	if (list == NULL || *list == NULL)
		return;
	temp = (*list)->next;
	for (; temp; temp = next)
	{
		next = temp->next;
		while (temp->prev && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (!temp->prev)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		temp = next;
	}
}

/**
 * swap_node - Swaps two nodes
 * @list: pointer to head of linked list
 * @a: The left item to swap.
 * @b: The right item to swap.
 */
void swap_node(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *tmp0 = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL;

	if ((a == NULL) || (b == NULL) || (list == NULL) || (a == b))
		return;
	tmp0 = a->prev, tmp1 = a->next, tmp2 = b->prev, tmp3 = b->next;
	if (a->prev == b)
	{
		a->next = b, a->prev = tmp2, b->next = tmp1, b->prev = a;
		if (tmp2 != NULL)
			tmp2->next = a;
		if (tmp1 != NULL)
			tmp1->prev = b;
	}
	else if (a->next == b)
	{
		a->next = tmp3, a->prev = b, b->next = a, b->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = b;
		if (tmp3 != NULL)
			tmp3->prev = a;
	}
	else
	{
		a->next = tmp3, a->prev = tmp2, b->next = tmp1, b->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = b;
		if (tmp1 != NULL)
			tmp1->prev = b;
		if (tmp2 != NULL)
			tmp2->next = a;
		if (tmp3 != NULL)
			tmp3->prev = a;
	}
	if (a->prev == NULL)
		*list = a;
	if (b->prev == NULL)
		*list = b;
}

/**
 * insertion_sort_li - Sorts doubly linked list
 * @list: A pointer to list for sorting
 */
void insertion_sort_li(listint_t **list)
{
	listint_t *node0 = NULL, *node1 = NULL, *node2 = NULL, *tmp = NULL;

	if (list != NULL)
	{
		node0 = *list == NULL ? NULL : (*list)->next;
		while (node0 != NULL)
		{
			node1 = node0;
			node2 = node1->prev;
			node0 = node0->next;
			while ((node1 != NULL) && (node2 != NULL))
			{
				tmp = node2;
				if (node2->n > node1->n)
				{
					swap_nodes(list, node1, node2);
					print_list(*list);
				}
				node1 = tmp;
				node2 = tmp->prev;
			}
		}
	}
}
