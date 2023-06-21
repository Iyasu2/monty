#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * _getline - Read a line from a file.
 * @lineptr: Pointer to the buffer that will store the line.
 * @n: Pointer to the size of the allocated buffer.
 * @stream:  The input stream to read from.
 * Return: The number of characters read, or -1 on failure or end of file.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
ssize_t size = 0;
char *line = NULL, *new_line = NULL;
int c;
ssize_t chars_read = 0;

while ((c = getc(stream)) != EOF)
{
if (size <= chars_read + 1)
{
size += 128;
new_line = realloc(line, size);
if (new_line == NULL)
{
free(line);
return (-1);
}
line = new_line;
}

line[chars_read] = c;
chars_read++;

if (c == '\n')
break;
}

if (chars_read == 0)
return (-1);

line[chars_read] = '\0';
*lineptr = line;
*n = size;
return (chars_read);
}

