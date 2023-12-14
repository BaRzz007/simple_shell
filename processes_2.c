#include "shell.h"

/**
 * execute_child_process - in the child process
 * it executes the command when it is
 * an executable
 * @cmd: a pointer to a pointer of the tokenized input
 * @full_path: pointer to the command full path
 */
void execute_child_process(char ***cmd, char **full_path)
{
	int exec_status;

	*full_path = in_path((*cmd)[0]);
	if (*full_path)
	{
		exec_status = execve(*full_path, *cmd, environ);
	}
	else
	{
		exec_status = execve((*cmd)[0], *cmd, environ);
	}
	if (exec_status == -1)
	{
		free_and_error(*cmd, "execve");
		_exit(EXIT_FAILURE);
	}
	free(*cmd);
}

/**
 * free_and_error - handles errors
 * @cmd: holds tokenized strings
 * @error_message: constant error message for handing errors
 */
void free_and_error(char **cmd, const char *error_message)
{
	char **temp;

	perror(error_message);
	if (cmd != NULL)
	{
		temp = cmd;
		while (*temp != NULL)
		{
			free(*temp);
			temp++;
		}
		free(cmd);
	}
	exit(EXIT_FAILURE);
}
