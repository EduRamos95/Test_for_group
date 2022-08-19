#include "monty.h"
/**
 * last_node - top of stack.
 * 
 * @stack: pointer to head of stack; 
 * Return: stack_t* 
 */
stack_t *last_node(stack_t **stack)
{
    stack_t *top;
    if(*stack == NULL)
        return (NULL);
    top = *stack;
    while (top->next != NULL)
        top = top->next;

    return (top);
}
