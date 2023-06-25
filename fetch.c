#include "monty.h"

/**
 * fetch - fetches line
 *
 * @buffer: buffer
 * @len_buff: lenght of buffer
 * @file: inout file
 *
 * Return: index
 */

size_t fetch(char **buffer, size_t *len_buff, FILE *file)
{
	int chr;
	size_t index = 0;
	char *temp;

	if (*buffer == NULL || *len_buff == 0)
	{	*len_buff = 128;
		*buffer = (char *)malloc(*len_buff * sizeof(char));
		if (*buffer == NULL) /*malloc error*/
		{	perror("Malloc error\n");
			exit(EXIT_FAILURE);
		}
	}
	/*read file character by character */
	while ((chr = getc(file)) != EOF)
	{
		if (index >= *len_buff - 1) /* if buffer full*/
		{	*len_buff *= 2; /*double it's size*/
			temp = (char *)realloc(*buffer, *len_buff * sizeof(char));
			if (temp == NULL) /*malloc fail*/
			{	perror("Malloc error\n");
				exit(EXIT_FAILURE);
			}
			*buffer = temp;
		}
		(*buffer)[index++] = chr;
		if (chr == '\n') /*break if newline*/
			break;
	}
	if (index == 0 && chr == EOF) /*eof reached+no chars read */
		return ((size_t)-1);
	(*buffer)[index] = '\0';
	return (index);
}
