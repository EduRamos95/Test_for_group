#include "monty.h"
/**
 * check_for_digit - checks that a string only contains digits
 * @arg: string to check
 *
 * Return: 0 if only digits, else 1
 */
static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * _push - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node_end(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}

/**
  * print_dlistint - prints a doubly linked list
  * @h: Head of the list
  */
void print_stack_t(stack_t *head)
{
    size_t i;
    stack_t *ptr;

	if (head == NULL)
		return;
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

void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *print_all;
    
    print_all = *stack;
    print_stack_t(print_all);
}

void _pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *ptr;
    ptr = *stack;

    while (ptr->next != NULL)
        ptr = ptr->next;

    printf("%d\n", ptr->n);
}

void _pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *ptr;
	stack_t *tmp;
    ptr = *stack;
	if ((*stack == NULL) || (var.stack_len == 0))
		return;
    while (ptr->next != NULL)
        ptr = ptr->next;
    /*elemento final*/
	if(ptr->prev != NULL)
	{
		tmp = ptr->prev;
		tmp->next = NULL;
	}
	free_stack(ptr);
	var.stack_len--;
}

void _swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *ptr = NULL;
    stack_t *tmp_1 = NULL;
    int num1 = 0;
    int num2 = 0;

    ptr = *stack;

    while (ptr->next != NULL)
        ptr = ptr->next;

    tmp_1 = ptr->prev;
    
    num1 = ptr->n;
    num2 = tmp_1->n;

    ptr->n = num2;
    tmp_1->n = num1;
}

void _add(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = NULL;
	stack_t *tmp_1 = NULL;
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	ptr = *stack;

	if (stack == NULL)
		return;

	while (ptr->next != NULL)
		ptr = ptr->next;

	if (var.stack_len >= 2)
	{
		tmp_1 = ptr->prev;

		num1 = ptr->n;
		num2 = tmp_1->n;
		sum = num1 + num2;

		tmp_1->n = sum;
		tmp_1->next = NULL;
		free(ptr);
		var.stack_len--;
	}
	else
	{
		return;
	}
}

void _nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{	
	printf("::nada::");
	return;
}