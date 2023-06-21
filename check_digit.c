#include "main.h"

/**
  * check_digit - entry point
  * @str: The string checked
  *
  * Return: 1 if all are digits, 0 if not
  */
int check_digit(char *str)
{
	int status = 1;

	while (*str != '\0')
	{
		if (str[0] == 45)
		{
			++str;
			continue;
		}

		if (isdigit(*str) == 0)
		{
			status = 0;
			return (status);
		}

		++str;
	}

	return (status);
}
