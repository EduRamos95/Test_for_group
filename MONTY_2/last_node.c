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

/**
 * first_node - bot of stack.
 * 
 * @stack: pointer to top of stack; 
 * Return: stack_t* 
 */
stack_t *first_node(stack_t **stack)
{
    stack_t *bot;
    if(*stack == NULL)
        return (NULL);
    bot = *stack;
    while (bot->prev != NULL)
        bot = bot->prev;

    return (bot);
}
