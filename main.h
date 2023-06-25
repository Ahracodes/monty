#ifndef _MAIN_H_
#define _MAIN_H_

/* LIBRARIES */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* FUNCTIONS */

int main(int argc, char *argv[]);
size_t newgetline(char **line, size_t *len_line, FILE *file);
void exec(char *line, unsigned int nb_line);
void push(int val, unsigned int nb_line);
void pall();
void pint(unsigned int nb_line);
void pop(unsigned int nb_line);
void swap(unsigned int nb_line);
size_t fetch(char **buffer, size_t *len_buff, FILE *file);

/* DEFINITIONS */
#define STACK_STORAGE 1024
extern int stack[STACK_STORAGE];
extern unsigned int stack_size;

/*STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


#endif
