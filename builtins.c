#include "shell.h"

/**
 * built_exit - Handles the exit built in command
 * @data: member of struct for the program data
 * @exit_int: exit status integer
 * Return: 0 on success
 */
int built_exit(program *data, int exit_int)
{
	free(data->tokens);
	free(data->command_name);
	exit(exit_int);
}
