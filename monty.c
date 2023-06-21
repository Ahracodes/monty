#include "main.h"

/**
 * main - main func
 *
 * @argc: arg count
 *
 * @argv: pointer to string of args
 *
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	(void) argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}
	return (0);
}
