#include "shell.h"

/**
 * handle_signal - handle signal
 *
 * @signum: signal number
 * Return: 0
 */
void handle_signal(int signum)
{
	if (signum == SIGINT)
		write(1, "\nFizz=->> ", 10);
}
