#include "shell.h"

/**
 * str_strdup - for duplicating string
 * @str: pointer to the string
 * Return:a pointer to  the duplicated string
 */
char *str_strdup(char *str)
{
	char *str2;
	size_t strL;

	if (!str)
		return (NULL);
	strL = str_strlen(str);
	str2 = (char *)malloc(strL + 1);
	if (str2 == NULL)
		return (NULL);
	str_strcpy(str2, str);
	return (str2);
}

/**
 * str_strlen - string lent
 * @str: string to determine the length
 * Return: the length of the string
 */
size_t str_strlen(char *str)
{
	size_t count;
	char *pointer;

	count = 0;
	pointer = str;
	while (*pointer != '\0')
	{
		count++;
		pointer++;
	}
	return (count);
}

/**
 * str_strcpy - to copy string
 * @str2: destination to copy string to
 * @str: string to copy
 * Return: a pointer to str2
 */
char *str_strcpy(char *str2, char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		str2[count] = str[count];
		count++;
	}
	str2[count] = '\0';
	return (str2);
}

/**
 * str_strcat - for concatenate str1 to str2
 * @str2: the str where str1 will be concatenated
 * @str1: string to be concatenated
 * Return: a pointer to str2
 */
char *str_strcat(char *str2, char *str1)
{
	int i, j;

	for (i = 0; str2[i] != '\0'; i++)
	{
		;
	}
	for (j = 0; i >= 0; )
	{
		str2[i] = str1[j];
		j++;
		i++;
		if (str1[j] == '\0')
		{
			str2[i] = '\0';
			break;
		}
	}
	return (str2);
}

/**
 * str_strncmp - compare a give number of string
 * @str1: first string to compare
 * @str2: second comparing string
 * @m: number of charcters to compare
 * Return: int 0 if equall, 1 if str1 > str2
 * -1 otherwise
 */
int str_strncmp(char *str1, char *str2, int m)
{
	int i, j;

	j = 0;
	for (i = 0; i < m; i++)
	{
		if (str1[i] == str2[i])
			j = 0;
		else if (str1[i] > str2[i])
			j = 1;
		else
			j = -1;
	}
	return (j);
}
