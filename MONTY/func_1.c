#include "monty.c"


void _push(stack_t **stack, __attribute__((unused))  unsigned int line_number)
{
    add_dnode_stack_t_end(stack, mont.num);
}

void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *print_all;
    
    print_all = *stack;
    print_stack_t(print_all);
}
