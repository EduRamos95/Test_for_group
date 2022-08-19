/*imprimir reversa lista doble*/
/*agregar al final lista doble*/
/*eliminar el final lista doble*/
/*contar elementos lista doble*/
/*ingresar al elemento de lista doble*/
#include "monty.h"
/**
  * print_dlistint - prints a doubly linked list
  * @h: Head of the list
  */
void print_stack_t(stack_t *head)
{
    size_t i;
    stack_t *ptr;

    ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    /*ubicacion en top*/
    /*i : cuenta elementos*/
    for (i = 0; ptr; i++)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->prev;
    }
}

/**
 * add_dnodeint_end - add node to end of doubly linked list
 * @head: pointer to head of list
 * @n: node data
 * Return: address of new node, or Null if failed
 */
stack_t *add_dnode_stack_t_end(stack_t **head, const int n)
{
	stack_t *new, *last;

	if (!head)
		return (NULL);
	/* malloc and set new node data */
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	/* account for empty linked list */
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
		return (new);
	}
	/* traverse to last node and insert */
	last = *head;
	while (last->next != NULL)
		last = last->next;
	/*new element in the end.. so next element is NULL*/
	new->next = NULL;
	/*previous element of new is 'last'*/
	new->prev = last;
	/*in the last element replace*/
	/*next->NULL to next->new*/
	last->next = new;
	return (new);
}
