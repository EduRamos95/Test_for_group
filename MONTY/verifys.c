#include "monty.h"

int verify_token(char *token)
{
    int i = 0;
    for (;token[i];i++)
    {
        if (token[i] > 57 || token[i] < 48)
            return (-1);
    }
    return (0);
}
