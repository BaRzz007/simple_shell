#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>

#define TRUE 1
#define FALSE 0

/**
 * struct program - it stores basic information of the program
 * @tokens: store the tokens gotten from the user input
 * @command_name: the first token retrievedy for changing purpose
 *
 * Description: This struct handles a program
 * by storing valuable information like the
 * tokens and command_name
 */
typedef struct program
{
	char **tokens;
	char *command_name;
} program;

/**
 * struct dir - for dir datas
 * @previous_dir: previous dir array
 * @num: for tracking number of dir
 *
 * Description: this struct holds some data for cd
 */
typedef struct dir
{
	char **previous_dir;
	size_t *num;
} cds;


char **tokenize(char *str, char *delim);
void handle_signal(int);
void handle_signal2(int);
char *in_path(char *);
int _strcmp(const char *s1, const char *s2);
int built_exit(program *data, int exit_int);

void setup_shell(char **buf, size_t *n);
int handle_input(char **, size_t *, program *, int *, int *);
pid_t create_process(char ***cmd);
void process_input(char *buf, program *data, int *count, cds *cd);
void execute_process(pid_t pid, int *status, char **cmd);
void free_and_error(char **cmd, const char *error_message);
void execute_child_process(char ***cmd, char **full_path);


void update_pwd(char *new_pwd);
void update_old(char *oldpwd);
char *obtain_cpwd();
void built_cd(char **cmd, cds *cd);
void handle_dir(char *target, char *pre, cds *cd);
void handle_dir_back( char *pre, cds *cd);
int _setenv(const char *, const char *, int);
cds init();

extern char **environ;

#endif
