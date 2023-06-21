#include "monty.h"

/**
  * execute - entry point
  * @op_code: operation code to be executed
  * @op_param: The parameter of the current operation
  * @line: current line read
  * @m: status
  *
  * Return: 0 if success or errcode if not
  */
int execute(char *op_code, char *op_param, unsigned int line, int m)
{
	int status_op = 0;

	oprt = func_list(op_code);
	if (oprt)
	{
		if (strcmp(op_code, "push") == 0)
		{
			oprt(&head, atoi(op_param));
		}
		else
		{
			oprt(&head, line);
		}

		return (m);
	}

	return (ERR_BAD_INST);
}
