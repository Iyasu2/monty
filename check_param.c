/**
  * check_param - entry point
  * @param: The parameter checked
  *
  * Return: 0 if is a valid, errcode if not
  */
int check_param(char *param)
{
	if (param == NULL || check_digits(param) == 0)
		return (300);

	return (0);
}
