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
	else
		return;

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
		default:
			break;
	}
}
