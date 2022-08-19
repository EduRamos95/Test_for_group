#include "monty.h"
/**
 * get_opc - Function that selects which one of the
 * @command: name of command.
 */
void (*get_opc(char *command))(stack_t **stack, unsigned int line_number)
{
	int mv = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (op[mv].opcode != NULL)
	{
		if (!strcmp(op[mv].opcode, command))
			return (op[mv].f);
		mv++;
	}
    return (NULL);
}
