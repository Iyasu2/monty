#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * _setenv - the value of an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * @overwrite: Flag indicating whether to overwrite an existing value.
 * Return: 0 on success, -1 on failure.
 */

int _setenv(const char *name, const char *value, int overwrite)
{

char *env_var = getenv(name);
if (env_var != NULL && !overwrite)
{
return (0);
}
size_t name_len = strlen(name);
size_t value_len = strlen(value);
size_t total_len = name_len + value_len + 2;
char *new_env_var = (char *)malloc(total_len);
if (new_env_var == NULL)
{
return (-1);
}
snprintf(new_env_var, total_len, "%s=%s", name, value);


if (env_var != NULL)
{

int result = putenv(new_env_var);
if (result != 0)
{
free(new_env_var);
return (result);
}
}
else
{

int result = putenv(new_env_var);
if (result != 0)
{
free(new_env_var);
return (result);
}
}

return (0);
}
