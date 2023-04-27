#include "sort.h"

/**
 * node_swap - Swap nodes in doubly linked list.
 * @list: pointer to head of linked list.
 * @l: left item to swap.
 * @r: right item to swap.
 */
void node_swap(listint_t **list, listint_t *l, listint_t *r)
{
	listint_t *tmp0 = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL;

	if ((l == NULL) || (r == NULL) || (list == NULL) || (l == r))
		return;
	tmp0 = l->prev, tmp1 = l->next, tmp2 = r->prev, tmp3 = r->next;
	if (l->prev == r)
	{
		l->next = r, l->prev = tmp2, r->next = tmp1, r->prev = l;
		if (tmp2 != NULL)
			tmp2->next = l;
		if (tmp1 != NULL)
			tmp1->prev = r;
	}
	else if (l->next == r)
	{
		l->next = tmp3, l->prev = r, r->next = l, r->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = r;
		if (tmp3 != NULL)
			tmp3->prev = l;
	}
	else
	{
		l->next = tmp3, l->prev = tmp2, r->next = tmp1, r->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = r;
		if (tmp1 != NULL)
			tmp1->prev = r;
		if (tmp2 != NULL)
			tmp2->next = l;
		if (tmp3 != NULL)
			tmp3->prev = l;
	}
	if (l->prev == NULL)
		*list = l;
	if (r->prev == NULL)
		*list = r;
}

/**
 * tail - retrieves tail node of doubly linked list.
 * @list: pointer to head of linked list.
 *
 * Return: tail of linked list, else NULL.
 */
listint_t *tail(listint_t **list)
{
	listint_t *node = NULL;

	if (list != NULL)
	{
		node = *list;
		while ((node != NULL) && (node->next != NULL))
			node = node->next;
	}
	return (node);
}

/**
 * cocktail_sort_list - Sorts doubly linked list
 * @list: The list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	char swap = FALSE;
	listint_t *node = NULL, *next = NULL, *tmp;

	if (list == NULL)
		return;
	do {
		node = *list;
		next = (node == NULL ? NULL : node->next);
		swap = FALSE;
		while ((node != NULL) && (next != NULL))
		{
			tmp = next;
			if (node->n > next->n)
			{
				node_swap(list, node, next);
				swap = TRUE;
				print_list(*list);
			}
			node = tmp, next = (node == NULL ? NULL : node->next);
		}
		if (!swap)
			break;
		swap = FALSE;
		next = tail(list);
		node = next == NULL ? NULL : next->prev;
		while ((node != NULL) && (next != NULL))
		{
			tmp = node;
			if (node->n > next->n)
			{
				node_swap(list, node, next);
				swap = TRUE;
				print_list(*list);
			}
			next = tmp, node = next == NULL ? NULL : next->prev;
		}
	} while (swap);
}
