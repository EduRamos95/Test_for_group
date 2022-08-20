#include "monty.h"
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;
	stack_t *tmp_1 = NULL;
	stack_t *tmp_2 = NULL;

	if ((*stack == NULL) && (var.stack_len == 0))
	{
		fprintf(stderr,"L%u: can't swap, stack too short\n",line_number);
		free(var.gline);
		fclose(var.gfs);
		exit(EXIT_FAILURE);
	}

	if (((*stack)->next == NULL) && (var.stack_len == 1))
	{
		fprintf(stderr,"L%u: can't swap, stack too short\n",line_number);
		if (*stack != NULL)
		{
			free_stack(*stack);
		}
		free(var.gline);
		fclose(var.gfs);
		exit(EXIT_FAILURE);
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
			tmp_2 = malloc(sizeof(stack_t));
			if (tmp_2 == NULL)
			{
				fprintf(stderr,"error de malloc\n");
				exit(EXIT_FAILURE);
			}
			tmp_1 = tmp_2;
			tmp_2 = NULL;
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

void _add(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = NULL;
	stack_t *tmp_1 = NULL;
	ptr = *stack;

	if (*stack == NULL || var.stack_len <= 1)
	{
		fprintf(stderr,"L%u: can't add, stack too short\n",line_number);
		if (*stack != NULL)
		{
			free_stack(*stack);
		}
		free(var.gline);
		fclose(var.gfs);
		exit(EXIT_FAILURE);
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
		fprintf(stderr,"L%u: can't add, stack too short\n",line_number);
		if (*stack != NULL)
		{
			free_stack(*stack);
		}
		free(var.gline);
		fclose(var.gfs);
		exit(EXIT_FAILURE);
	}
}

void _nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{	
	/*printf("::nada::");*/
	return;
}