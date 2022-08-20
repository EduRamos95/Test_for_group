#include "monty.h"

/**
 * add_node_end - add a new node to a doble linked list
 * @stack: double pointer to the beginning of the double linked list
 * @n: value to add to the new node
 *
 * Description: the function will add the node to the begining if in
 * stack mode and the end if in queue mode
 *
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node_end(stack_t **stack, const int n)
{
	stack_t *new;
	stack_t *ptr;

	ptr = *stack;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
		new->next = NULL;
	}
	if (var.queue == STACK && var.stack_len == 0)
		(*stack) = new;
	return (new);
}