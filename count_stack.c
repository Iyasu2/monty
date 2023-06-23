#include "monty.h"

/**
  * count_stack - entry point
  * @stack: The stack to count
  *
  * Return: Number of elements in the stack
  */
unsigned int count_stack(stack_t *stack)
{
	stack_t *current = stack;
	unsigned int length = 0;

	while (current != NULL)
	{
		++length;
		current = current->next;
	}

	return (length);
}
