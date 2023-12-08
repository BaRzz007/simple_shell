#include "shell.h"

/*
 * built_exit - Handles the exit built in command
 * @data: member of struct for the program data
 * Return: 0 to exit the shell
 */
int built_exit(program *data)
{
	free(data->tokens);
	free(data->command_name);
	exit(0);
}
