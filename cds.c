#include "shell.h"

/**
 * obtain_cpwd - get old working directory
 * Return: current working directory
 */
char *obtain_cpwd()
{
	return (getcwd(NULL, 0));
}

/**
 * built_cd - the main engine to
 * changingworking directory manipulation
 * the main function for cd
 * @cd: to keep track of the number of dirs
 * @cmd: pointer to cmd
 */
void built_cd(char **cmd, cds *cd)
{
	char *pre_dir, *target_dir;

	pre_dir = obtain_cpwd();
	target_dir = (cmd[1] != NULL) ? cmd[1] : getenv("HOME");
	if (_strcmp(target_dir, "-") != 0)
	{
		handle_dir(target_dir, pre_dir, cd);
	}
	else if (cmd[1] && _strcmp(target_dir, "-") == 0)
	{
		handle_dir_back(target_dir, cd);
	}
	else
	{
		perror("cd");
	}
}

/**
 * handle_dir - for add dirs to array and changing them
 * @target: target dir
 * @pre: previous dir
 * @cd: structof previous_dir
 */
void handle_dir(char *target, char *pre, cds *cd)
{
	if (chdir(target)  == -1)
	{
		perror("cd");
	}
	else
	{
		cd->previous_dir[*(cd->num)] = strdup(pre);
		if (cd->previous_dir[*(cd->num)] != NULL)
		{
			++(*(cd->num));
		}
		else
		{
			perror("memory full");
		}
	}
}

/**
 * handle_dir_back - for handling cd -
 * @pre: previous dir
 * @cd: struct of previous_dir
 */
void handle_dir_back(char *pre, cds *cd)
{
	size_t b, t;
	char *pat, *i;

	b = *(cd->num);
	t = 0;
	if (pre != NULL && b > t)
	{
		if (chdir(cd->previous_dir[--(*(cd->num))]) == -1)
		{
			perror("chdir");
		}
		else
		{
			free(cd->previous_dir[++(*(cd->num))]);
					--(*(cd->num));
			_setenv("PWD", cd->previous_dir[*(cd->num)], 1);
		}
	}
	else
	{
		pat = obtain_cpwd();
		if (chdir(getenv("HOME")))
		{
			perror("getenv");
		}
		else
		{
			i = obtain_cpwd();
			cd->previous_dir[--(*(cd->num))] = strdup(i);
			++(*(cd->num));
			cd->previous_dir[*(cd->num)] = strdup(pat);
			++(*(cd->num));
		}
	}
}
