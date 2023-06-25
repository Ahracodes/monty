#include "main.h"

/**
 * main - monty main func
 *
 * @argc: arg count
 *
 * @argv: arg vec
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len_line = 0;
	size_t read;
	unsigned int nb_line = 0;

	if (argc != 2) /* check if correct number of args */
	{	fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r"); /* open file from arg */
	if (file == NULL) /* file opn error */
	{	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	/* while lines left to read in file */
	while ((read = fetch(&line, &len_line, file)) != (size_t)-1)
	{	nb_line++;
		exec(line, nb_line); /*execute line */
	}

	free(line);
	fclose(file); /* close file */

	return (0); /* for success */
}
