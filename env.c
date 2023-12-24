#include "shell.h"

/**
 * env_getenv - finds an enviroment acvording to
 * to the name given if seen in environ
 * @name: name of the entered environment
 * Return: NULL if no match enviroment
 * to name
 */
char *env_getenv(char *name)
{
	char **envir;
	int tean;

	envir = environ;
	if (name == NULL)
		return (NULL);
	while (envir != NULL)
	{
		tean = str_strncmp(*envir, name, str_strlen(name));
		if (tean == 0 && (*envir)[str_strlen(name)] == '=')
		{
			return (*envir + str_strlen(name + 1));
		}
		++envir;
	}
	return (NULL);
}

