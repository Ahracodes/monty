#include "monty.h"

int stack[STACK_STORAGE];
unsigned int stack_size = 0;

/**
 * push - pushes int onto stack
 *
 * @val: value to be pushed
 *
 * @nb_line: current number of lines
 *
 * Return: void
 */
void push(int val, unsigned int nb_line)
{
	if (stack_size >= STACK_STORAGE) /* stack is full */
	{	fprintf(stderr, "L%u: error: stack overflow\n", nb_line);
		exit(EXIT_FAILURE);
	}
	stack[stack_size] = val; /* push */
	stack_size++; /*increment stack size */
}

/**
 * pall - prints all elements in stack from the top
 *
 * Return: void
 */
void pall(void)
{
	size_t x;

	/* prints all elements through iterating */
	for (x = stack_size; x > 0; x--)
	{	printf("%d\n", stack[x - 1]);
	}
}

/**
 * pint - print value in top of stack
 *
 * @nb_line: current number of lines
 *
 * Return: void
 */
void pint(unsigned int nb_line)
{
	if (stack_size > 0) /* if stack not empty */
		printf("%d\n", stack[stack_size - 1]);
	else /* if empty */
	{	fprintf(stderr, "L%u: can't pint, stack empty\n", nb_line);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - remove top element from stack
 *
 * @nb_line: current number of lines
 *
 * Return: void
 */
void pop(unsigned int nb_line)
{
	if (stack_size > 0) /* if stack not empty */
		stack_size--; /*decrement size of stack = pop top element */
	else
	{	fprintf(stderr, "L%u: can't pop an empty stack\n", nb_line);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swap top two elements
 *
 * @nb_line: number of lines
 *
 * Return: void
 */

void swap(unsigned int nb_line)
{
	int tmp;

	if (stack_size >= 2) /* if at least two elements */
	{	tmp = stack[stack_size - 1];
		stack[stack_size - 1] = stack[stack_size - 2];
		stack[stack_size - 2] = tmp;
	}
	else
	{	fprintf(stderr, "L%u: can't swap, stack too short\n", nb_line);
		exit(EXIT_FAILURE);
	}
}
