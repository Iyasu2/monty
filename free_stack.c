#include "main.h"

/**
  * free_stack - entry point
  *
  * Return: None
  */
void free_stack(void)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = head;

		while (temp)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
}
