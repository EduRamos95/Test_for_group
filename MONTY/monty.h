#ifndef _MONTY_H_
#define _MONTY_H_
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char **environ;

/**
 *GLOBAL_s - opcode and its function
 *a
 *a
 *a
 */
typedef struct GLOBAL_s
{
	char *buff;
	unsigned int line_number;
	int num;
	int len;
	FILE *script;
} GB_t;
extern GB_t mont;

void (*get_opc(char *command))(stack_t **stack, unsigned int line_number);
int verify_token(char *token);

/*mandatory functions*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/*node_manipulate.c*/
void print_stack_t(stack_t *head);
stack_t *add_dnode_stack_t_end(stack_t **head, const int n);
/*free_dlist.c*/
void free_stack(stack_t *head);
#endif
