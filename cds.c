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
 * @data: program data info holder
 * @cmd: pointer to cmd
 */
void built_cd(char **cmd)
{
	char *pre_dir, *current_dir, *target_dir;
	cds cd;

	cd.num = 0;
	pre_dir = obtain_cpwd();
	target_dir = (cmd[1] != NULL) ? cmd[1] : getenv("HOME");
	if (_strcmp(target_dir, "-") != 0)
	{
		if (chdir(target_dir) == -1)
		{
			perror("cd");
		}
		else
		{
			cd.previous_dir[cd.num] = strdup(pre_dir);
			if (cd.previous_dir[cd.num] != NULL)
			{
				++cd.num;
			}
			else
			{
				perror("memory full");
			}
		}
	}
	else if (cmd[1] && _strcmp(cmd[1], "-") == 0)
	{
		if (pre_dir != NULL)
		{
			if (chdir(cd.previous_dir[cd.num]) ==-1)
			{
				perror("chdir");
			}
			else
			{
				_setenv("PWD", cd.previous_dir[cd.num];
			}
		}
		else
		{
			perror("cd");
		}
	}
	for (int i = 0; i < (sizeof( cd.previous_dir)/sizeof(cd.previous_dir[0])); ++i)
	{
		printf("dir at position %d is %s\n", i, cd.previous_dir[i]);
	}
}
