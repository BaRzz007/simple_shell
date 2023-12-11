#include "shell.h"

/*
 *
 *
 *
 */
void process_input(char *buf, program *data, int *count)
{
	char **cmd;
	int *status, exit_int;
	pid_t pid;

	status = 0;
	cmd = tokenize(buf, " \t\n");
	if (cmd[0] == NULL)
	{
		(*count)++;
		return;
	}
	if (_strcmp(cmd[0], "exit") == 0)
	{
		exit_int = 98;
		built_exit(data, exit_int);
	}
	pid = create_process(&cmd);
	if (pid == -1)
	{
		free_and_error(cmd, "Failed to fork");
		exit(1);
	}
	execute_process(pid, status, cmd);
	(*count)++;
}

/*
 *
 *
 */
pid_t create_process(char ***cmd)
{
	char *full_path;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execute_child_process(cmd, &full_path);
	}
	return( pid);
}

/*
 *
 *
 *
 */
void execute_process(pid_t pid, int *status, char **cmd)
{
	if (pid != 0)
	{
		waitpid(pid, status, 0);
		free(cmd);
	}
}
