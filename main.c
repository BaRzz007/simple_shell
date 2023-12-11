#include "shell.h"

/**
 * main - Entry point to the shell program
 *
 * Return: 0 if success, 1 on failure
 */
int main(void)
{
	size_t n;
	char *buf;
	int count;
	program data;

	buf = NULL;
	count = 0;
	n = 0;
	data.tokens =NULL;
	data.command_name = NULL;
	while (1)
	{
		signal(SIGINT, handle_signal);
		write(STDIN_FILENO, "Fizz->> ", 9);
		if (getline(&buf, &n, stdin) == -1)
		{
			write(STDIN_FILENO, "\n", 1);
			break;
		}
		process_input(buf, &data, &count);
	}
	free(buf);
	return (0);
}
