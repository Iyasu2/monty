#include "monty.h"

stack_t *head = NULL;

/*
  * main - entry point
  * @argint: number of arguments
  * @argstr: array of arguments
  *
  * Return: Always zero
  */

int main(int argint, char *argstr[])
{
	FILE *fd = NULL;
	int read = 0, op_status = 0;
	char *filename = NULL, *op_code = NULL, *op_param = NULL, *buffer = NULL;
	size_t line_len = 0;
	unsigned int line_num = 1;

	filename = argstr[1];
	check_args_num(argint);
	fd = open_file(filename);

	while ((read = _getline(&buffer, &line_len, fd)) != -1)
	{
		op_code = strtok(buffer, "\t\n ");
		if (op_code)
		{
			if (op_code[0] == '#')
			{
				++line_num;
				continue;
			}

			op_param = strtok(NULL, "\t\n ");
			op_status = execute(op_code, op_param, line_num, op_status);

			if (op_status >= 100 && op_status < 400)
			{
				fclose(fd);
				handle_error(op_status, op_code, line_num, buffer);
			}
		}

		++line_num;
	}
	free_stack();
	free(buffer);
	fclose(fd);
	return (0);
}
