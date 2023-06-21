#include "main.h"

/**
  * check_param - entry point
  * @param: The parameter checked
  *
  * Return: 0 if is a valid, errcode if not
  */
int check_param(char *param)
{
	if (param == NULL || check_digit(param) == 0)
		return (ERR_PUSH_USG);

	return (0);
}
