#include "shell.h"

/**
 * process_input - this function handles
 * the input gotten from the commandline
 * @buf: it is a container holding the input entered by the  user
 * @data: holds informationfor further processing
 * @count: counter for keeping track the
 * of the program
 * @cd: tracking number of dir
 */
void process_input(char *buf, program *data, int *count, cds *cd)
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
		exit_int = 232;
		built_exit(data, exit_int);
	}
	else if (_strcmp(cmd[0], "cd") == 0)
	{
		built_cd(cmd, cd);
	}
	else
	{
		pid = create_process(&cmd);
		if (pid == -1)
		{
			free_and_error(cmd, "Failed to fork");
			exit(1);
		}
		execute_process(pid, status, cmd);
		(*count)++;
	}
}

/**
 * create_process - responsible of stating a process
 * @cmd: pointer to the pointer of cmd, which holds the tokenied input
 * Return: pid when successful
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
	return (pid);
}

/**
 * execute_process - incharge of excuting the command and stating a
 * new process when found
 * @pid: process id of the current process
 * @status: staus of the process
 * @cmd: pointer to commandline tokenized
 * string
 */
void execute_process(pid_t pid, int *status, char **cmd)
{
	if (pid != 0)
	{
		waitpid(pid, status, 0);
		free(cmd);
	}
}
