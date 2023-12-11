#include "shell.h"

/*
 *
 *
 *
 */
void execute_child_process(char ***cmd, char **full_path)
{
	int exec_status;

	if ((*full_path = in_path((*cmd)[0])))
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

/*
 *
 *
 *
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
