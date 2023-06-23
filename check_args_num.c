#include "monty.h"

/**
  * check_args_num - entry point
  * @argint: argument number
  *
  * Return: None
  */
void check_args_num(int argint)
{
	if (argint != 2)
		handle_error(ERR_ARG_USG, NULL, 0, NULL);
}
