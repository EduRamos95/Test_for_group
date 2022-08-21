#include "monty.h"
/**
 * free_to_exit - free all mallocs
 * @head: head of stack
 */
void free_to_exit(stack_t *head)
{
	free_stack(head);
	free(var.gline);
	fclose(var.gfs);
	exit(EXIT_FAILURE);
}

/**
 * _pop - remove top element from stack
 * @stack: head of stack
 * @line_number: number file line
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	stack_t *tmp;

	if ((stack == NULL) || (*stack == NULL) || (var.stack_len == 0))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_to_exit(*stack);
	}
	ptr = *stack;
	while (ptr->next != NULL)
		ptr = ptr->next;
	if (ptr->prev != NULL)
	{
		tmp = ptr->prev;
		free_stack(ptr);
		ptr = tmp;
		ptr->next = NULL;
	}
	if ((ptr->prev == NULL) && var.stack_len == 1)
	{
		free_stack(ptr);
		(*stack) = NULL;
	}
	var.stack_len--;
}

/**
 * _swap - swap the top 2 elements of stack
 * @stack: head of stack
 * @line_number: number file line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;
	stack_t *tmp_1 = NULL;
	stack_t *tmp_2 = NULL;

	if (var.stack_len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_to_exit(*stack);
	}
	ptr = *stack;
	while (ptr->next != NULL)
		ptr = ptr->next;
	if (var.stack_len >= 3)
	{
		tmp_1 = ptr->prev;
		tmp_2 = tmp_1->prev;
		tmp_2->next = ptr;
		ptr->prev = tmp_2;
		ptr->next = tmp_1;
		tmp_1->prev = ptr;
		tmp_1->next = NULL;
	}
	else
	{
		tmp_1 = malloc(sizeof(stack_t));
		if (tmp_1 == NULL)
		{
			fprintf(stderr, "error de malloc\n");
			free_to_exit(*stack);
		}
		tmp_1->prev = (*stack)->prev;
		tmp_1->next = (*stack);
		(*stack)->prev = ptr;
		(*stack)->next = NULL;
		ptr->next = tmp_1->next;
		ptr->prev = tmp_1->prev;
		tmp_1->next = NULL;
		free_stack(tmp_1);
		(*stack) = ptr;
	}
}

/**
 * _add - adds the top 2 elements to the stack
 * @stack: head of stack
 * @line_number: number file line
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;
	stack_t *tmp_1 = NULL;

	ptr = *stack;
	if (*stack == NULL || var.stack_len <= 1)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_to_exit(*stack);
	}

	while (ptr->next != NULL)
		ptr = ptr->next;

	if (((ptr->prev)->prev == NULL) || var.stack_len >= 2)
	{
		tmp_1 = ptr->prev;
		tmp_1->n += ptr->n;
		tmp_1->next = NULL;
		free_stack(ptr);
		var.stack_len--;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_to_exit(*stack);
	}
}

/**
 * _nop - does nothing
 * @stack: head of the stack
 * @line_number: number file line
 */
void _nop(stack_t **stack __attribute__((unused))
		, unsigned int line_number __attribute__((unused)))
{
}
