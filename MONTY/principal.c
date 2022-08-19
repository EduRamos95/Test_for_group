/**/
/*abrir el archivo monty*/
/**/
/*► obtener las lineas y linea_num*/
/*►► tokenizar para obtener el comando*/
/*►►► verificacion de comando*/
/*►► tokenizar para obtener el parametro*/
/*►►► verificacion de parametro*/
/*►►►► creación del puntero pila (malloc)*/
/*►►►►► ejecutar la funcion (point_pila, linea_num)*/
/*►►►►► pasa a la nueva linea */
/*► verificamos puntero pila NO es null*/
/*►► free a los elementos de la pila*/
/*► cerrar el archivo monty*/
/*retornar success*/
/**/
#include "monty.h"
GB_t mont = {NULL, 1, 0, 0, NULL};

int main(int argc, char *argv[])
{
	size_t len2 = 0;
	void (*point_func)(stack_t **stack, unsigned int line_number) = NULL;
	char *token;
	stack_t *ptr_stack;

	if(argc != 2)
	{
		printf("solo son 2 parametros");
		return(-1);
	}

	mont.line_number = 1;
	mont.script = fopen(argv[1], "r");
	while (getline(&mont.buff,&len2,mont.script) != -1)
	{
        /*verificar si funciono el getline*/
		if (mont.buff == NULL)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
        }
		token = strtok(mont.buff, "\n\t\r ");
		if (token != NULL)
		{
			point_func = get_opc(token);
			if (point_func == NULL)
				return (-1);
			token = strtok(NULL, "\n\t\r ");
			if (verify_token(token) == -1)
				return (-1);
			mont.num = atoi(token);
			point_func(&ptr_stack,mont.line_number);
		}
		free(mont.buff);
		mont.buff = NULL;
		len2 = 0;
		mont.line_number++;
	}
	if(ptr_stack != NULL)
		free_stack(ptr_stack);
	fclose(mont.script);
	mont.script = NULL;
	return(0);
}
