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
 * @num: to keep track of the number of dirs
 * @cmd: pointer to cmd
 */
void built_cd(char **cmd, size_t *num)
{
	char *pre_dir, *target_dir;
	cds cd;
	
	pre_dir = obtain_cpwd();
	cd.previous_dir = malloc(sizeof(char *) * 20);
	if (cd.previous_dir == NULL)
	{
		perror("memory fail");
	}
	target_dir = (cmd[1] != NULL) ? cmd[1] : getenv("HOME");
	if (_strcmp(target_dir, "-") != 0)
	{
		handle_dir(num, target_dir, pre_dir, &cd);
	}
	else if (cmd[1] && _strcmp(target_dir, "-") == 0)
	{
		handle_dir_back(num, target_dir, &cd);
	}
	else
	{
		perror("cd");
	}
}

/**
 * handle_dir - for add dirs to array and changing them
 * @num: keeping track of dir
 * @target: target dir
 * @pre: previous dir
 * @previous_dir: array of previous_dir
 */
void handle_dir(size_t *num, char *target, char *pre, cds *cd)
{
	size_t i;
	if (chdir(target)  == -1)
	{
		perror("cd");
	}
	else
	{
		cd->previous_dir[*num] = strdup(pre);
		printf("num is %ld pre is now %s\n", *num, cd->previous_dir[*num]);
		if (cd->previous_dir[*num] != NULL)
		{
			++(*num);
			printf("num increased to %ld\n", *num);
		}
		else
		{
			perror("memory full");
		}
	}
	for (i = 0; i < *num; ++i)
	{
		printf("previous_dir array %s\n", cd->previous_dir[i]);
	}
}

/**
 * handle_dir_back - for handling cd -
 * @num: for tracking number of dir
 * @pre: previous dir
 * @previous_dir: array of previous_dir
 */
void handle_dir_back(size_t *num, char *pre, cds *cd)
{
	if (pre != NULL)
	{
		if (chdir(cd->previous_dir[--(*num)]) == -1)
		{
			printf("previous_dir is %s\n", cd->previous_dir[0]);
		/*	perror("chdir");*/
		}
		else
		{
			_setenv("PWD", cd->previous_dir[*num], 1);
		}
	}
	else
	{
		perror("cd");
	}
}
