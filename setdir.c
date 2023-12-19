#include "shell.h"

/**
 * _setenv - to set enviroment variables
 * @name: variable name
 * @value: variable/env values
 * @overwrite: handle overwriting on var
 * Return: 0 on sucess and 1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int valueofL, len;
	char *new_var, *current, *existing;

	valueofL = 0;
	len = 0;
	if (name == NULL || *name == '\0')
		return (-1);
	if (strchr(name, '=') != NULL || value == NULL)
		return (-1);
	existing = getenv(name);
	if (existing != NULL && !overwrite)
		return (0);
	while (name[len] != '\0')
		++len;
	++len;
	while (value[valueofL])
		++valueofL;
	len += valueofL;
	new_var = (char *)malloc(len + 1);
	if (!new_var)
		return (-1);
	current = new_var;
	while (*name)
		*current++ = *name++;
	*current = '\0';
	if (putenv(new_var) != 0)
		return (-1);
	return (0);
}
