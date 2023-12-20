#include "shell.h"

/**
 * init - for initializing builtins
 * Return: the struct holding initializing info
 */
cds init(void)
{
	cds cd;

	cd.num = malloc(sizeof(size_t));
	if (cd.num == NULL)
	{
		perror("failed memory");
	}
	cd.previous_dir = malloc(sizeof(char *) * 20);
	if (cd.previous_dir == NULL)
	{
		perror("failed memory");

	}
	*(cd.num) = 0;
	return (cd);
}
