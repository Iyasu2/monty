#include "main.h"

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
	void (*oprt)(stack_t **, unsigned int);

	if (strcmp(op_code, "stack") == 0)
		return (STACK);
	else if (strcmp(op_code, "queue") == 0)
		return (QUEUE);
	oprt = func_list(op_code);
	if (oprt)
	{
		if (strcmp(op_code, "push") == 0)
		{
			status_op = check_param(op_param);
			if (status_op == ERR_PUSH_USG)
				return (ERR_PUSH_USG);

			if (m != 0 && m == QUEUE)
				oprt = func_list("push_queue");

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
