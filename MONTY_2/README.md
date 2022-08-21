# C - Stacks, Queues - LIFO, FIFO

[![montyy.jpg](https://i.postimg.cc/KYs2cGKj/montyy.jpg)](https://postimg.cc/QB5P0rJZ)

**About**

	Monty is a bytecode interpreter that Franco Cardenas and I built for Holberton 
	project: C - Stacks, Queues - LIFO, FIFO.

**Resources**

	* Google
	* How do I use extern to share variables between source files in C?

**Requirements**
** GENERAL **

    * Allowed editors: vi, vim, emacs
    * All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic
    * All your files should end with a new line
    * A README.md file, at the root of the folder of the project is mandatory
    * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    * You allowed to use a maximum of one global variable
    * No more than 5 functions per file
    * You are allowed to use the C standard library
    * The prototypes of all your functions should be included in your header file called monty.h
    * Don’t forget to push your header file
    * All your header files should be include guarded
    * You are expected to do the tasks in the order shown in the project

**GitHub**

      * There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

**MORE INFO**
**Data Structures**

      * Please use the following data structures for this project. Don’t forget to include them in your header file.

**Compilation & Output**
      
      * Your code will be compiled this way:
      gcc -Wall -Werror -Wextra -pedantic *.c -o monty
      * Any output must be printed on stdout
      * Any error message must be printed on stderr
      	* Here is a link to a GitHub repository that could help you making sure your errors are printed on stderr.

**Tests**
      
      * We strongly encourage you to work all together on a set of tests.

**The Monty Language**

      * Monty 0.98 is a scripting language that is first compiled into Monty
      byte codes (Just like Python). It relies on a unique stack, with specific
      instructions to manipulate it.
      the goal of this project is to create an interpreter for Monty ByteCodes files.

**Monty byte code files**

	* Files containing Monty byte codes usually have the .m extension. Most
	of the industry uses this standard but it is not required by the
	specification of the language.

**LIFO and FIFO**

      * FIFO - First in, First out. A method for organising and manipulating a
      data buffer.
      * LIFO - Last in, First out. The order in which elements come off a stack.

**Stacks and Queues**

      * Stacks - Storing elements in LIFO Style, data area or buffer used for
      storing requests that need to be handled.
      * Queues - Storing elements in FIFO style, and contains elements in
      precisely the order they were added

**push, pall, pint, pop, swap, add, nop**

	* push - The opcode push pushes an element to the stack.
	* pall - The opcode pall prints all the values on the stack, starting
	from the top of the stack.
	* pint - The opcode pint prints the value at the top of the stack,
	followed by a new line.
	* pop -  The opcode pop removes the top element of the stack.
	* swap - The opcode swap swaps the top two elements of the stack.
	* add - The opcode add adds the top two elements of the stack.
	* nop - The opcode nop doesn’t do anything.
	
**Authors:**

	* Franco Cardenas - Edu Ramos.
