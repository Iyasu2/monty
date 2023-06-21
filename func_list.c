#include "main.h"

/**
  * func_list - entry point
  * @s: The instruction to be executed
  *
  * Return: A pointer to the function to be executed or
  * NULL if the function doesn't exist
  */
void (*func_list(char *s))(stack_t **, unsigned int)
{
	instruction_t command[] = {
		{ "push", push },
		{ "push_queue", push_queue },
		{ "pall", pall },
		{ NULL, NULL }
	};
	int i = 0;

	while (command[i].opcode)
	{
		if (strcmp(s, command[i].opcode) == 0)
			return (command[i].f);

		++i;
	}

	return (NULL);
}
