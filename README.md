<p align="center">
  <img  src="https://ml.globenewswire.com/Resource/Download/a08e6c28-55be-44c8-8461-03544f094b38">
</p>


# Our printf function (_printf).

`_printf`  This is a function, created to emulate the basic functions of the original `printf`.

This function prints to the screen using a format string that includes instructions for mixing multiple strings into the final string to display on the screen.

## Prototype.
```c
int _printf(conts char * format, ...)
```
## Supported format specifiers types.
For this project we manage to print the following specifiers:
### Specifiers

Types | Output
------------- | -------------
c| Prints a char.
s| Prints a string.
i| Prints an integer.
d| Prints a decimal.

### Naturally Special Characters
Types | Output
------------- | -------------
%  | Prints a % .

##Basic Examples:
```c
#include "main.h"
{
	_printf("%c\n", 'H');
	_printf("%s\n", "Hello World!");
	return (0);
}
```
##### Output:
`H`
`Hello World!`

```c
#include "main.h"
#include <limits.h>
{
	_printf("%i\n", INT_MAX);
	_printf("%i\n", INT_MIN);
	return (0);
}
```
##### Output:
`2147483647`
`-2147483647`

```c
#include "main.h"
{
	_printf("%%");
	return (0);
}
```
##### Output:
`%`


### Compilation
Compiled with :  `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c`

## Authors
[Edu Ramos](https://github.com/EduRamos95)
[Kevin Espinoza](https://github.com/KevinYeff)
