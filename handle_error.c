#include "main.h"

/**
  * handle_error - entry point
  * @errno: The error code
  * @opcode: The operation code
  * @line: The line on which the error occurred
  * @buffer: The reserved error line buffer
  *
  * Return: None
  */
void handle_error(int errno, char *opcode, unsigned int line, char *buffer)
{
	if (errno >= 100 && errno < 200)
		handle_cerror(errno, opcode, line);
	else if (errno >= 300 && errno <= 310)
		handle_uerror(errno, line);
	else
		return;

	free_stack();

	if (buffer)
		free(buffer);

	exit(EXIT_FAILURE);
}

/**
  * handle_cerror - entry point
  * @errno: The error code
  * @opcode: The operation code
  * @line: The line on which the error occurred
  *
  * Return: None
  */
void handle_cerror(int errno, char *opcode, unsigned int line)
{
	switch (errno)
	{
		case ERR_BAD_INST:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case ERR_BAD_MALL:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
 * handle_uerror - entry point
 * @errno: The error code
 * @line: The line on which the error occurred
 *
 * Return: None
 */
void handle_uerror(int errno, unsigned int line)
{
	switch (errno)
	{
		case ERR_ARG_USG:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case ERR_PUSH_USG:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		default:
			break;
	}
}
