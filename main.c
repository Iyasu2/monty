#include "main.h"

/**
  * main - entry point
  * @argint: number of arguments
  * @argstr: array of arguments
  *
  * Return: Always zero
  */
int main(int argint, char *argstr[])
{
	FILE *fd = NULL;
	int read = 0;
	char *filename = NULL, *op_code = NULL, *op_param = NULL, *buffer = NULL;
	size_t line_len = 0;
	unsigned int line_num = 1;

	filename = args[1];
	if (argint != 2)
	{
		fprintf(stderr, "USAGE: monty file\n", filename);
		exit(EXIT_FAILURE);
	}
	fd = fopen(filename, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&buffer, &line_len, fd)) != -1)
	{
		op_code = strtok(buffer, "\t\n ");
		if (op_code)
		{
			if (op_code[0] == '#')
			{
				++line_num;
				continue;
			}
		}
		op_param = strtok(NULL, "\t\n ");

		++line_num;
	}
	free(buffer);
	fclose(fd);
	return (0);
}
