#ifndef MAIN_H
#define MAIN_H

/* Constants */
#define STACK	300
#define QUEUE	301

/* Common Errors */
#define ERR_BAD_INST	100
#define ERR_BAD_MALL	101

/* Usage Errors */
#define ERR_ARG_USG	200
#define ERR_PUSH_USG	201
#define ERR_PINT_USG	202
#define ERR_POP_USG	203
#define ERR_SWAP_USG	204
#define ERR_ADD_USG	205

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

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int execute(char *op_code, char *op_param, unsigned int line, int m);
void (*func_list(char *s))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int param);
void pall(stack_t **stack, unsigned int line_number);
void handle_error(int errno, char *opcode, unsigned int line, char *buffer);
void handle_cerror(int errno, char *opcode, unsigned int line);
int check_digit(char *str);
int check_param(char *param);
void check_access_rights(char *filename);
void handle_uerror(int errno, unsigned int line);
void free_stack(void);
void check_args_num(int argint);
FILE *open_file(char *filename);
void push_queue(stack_t **stack, unsigned int param);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
unsigned int count_stack(stack_t *stack);

#endif /* MAIN_H */
