#include "main.h"

/**
 * exec - execute the instructions
 *
 * @line: line
 *
 * @nb_line: number of lines
 *
 * Return: void
 */

void exec(char *line, unsigned int nb_line)
{
	char *opcode, *argument;
	int val;

	opcode = strtok(line, " \t\n"); /*tokenize using these delims */
	if (opcode == NULL || opcode[0] == '#')
		return; /*if NULL or comment do nothing */

	if (strcmp(opcode, "push") == 0)
	{	argument = strtok(NULL, " \t\n");
		if (argument == NULL) /* if no arg */
		{	fprintf(stderr, "L%u: usage: push integer\n", nb_line);
			exit(EXIT_FAILURE); /* error */
		}
		val = atoi(argument);
		push(val, nb_line); /* push val into stack */
	}
	else if (strcmp(opcode, "pall") == 0) /*print all vals in stack */
		pall();
	else if (strcmp(opcode, "pint") == 0) /* print val in top of stack */
		pint(nb_line);
	else if (strcmp(opcode, "pop") == 0)
		pop(nb_line); /* remove top val of stack */
	else if (strcmp(opcode, "swap") == 0)
		swap(nb_line); /*swap top two vals on stack */
	else /* if none of above */
	{	fprintf(stderr, "L%u: unknown instruction %s\n", nb_line, opcode);
		exit(EXIT_FAILURE);
	}
}
