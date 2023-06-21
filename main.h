#ifndef MAIN_H
#define MAIN_H

/* Common Errors */
#define ERR_BAD_INST	100

#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


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
extern stack_t *head;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute(char *op_code, char *op_param, unsigned int line, int m);
void (*func_list(char *s))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int param);
void pall(stack_t **stack, unsigned int line_number);
void handle_error(int errno, char *opcode, unsigned int line, char *buffer);
void handle_cerror(int errno, char *opcode, unsigned int line);
int check_digit(char *str);
int check_param(char *param);
void check_access_rights(char *filename);

#endif /* MAIN_H */
