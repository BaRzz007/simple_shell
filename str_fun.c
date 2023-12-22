#include "shell.h"

/**
 * str_strdup - for duplicating string
 * @str: pointer to the string
 * Return:a pointer to  the duplicated string
 */
char *str_strdup(const char *str)
{
	char str2;
	size_t strL;

	if (!(str))
		return (NULL);
	strL = _strlen(str);
	str2 = (char *)malloc(strL + 1);
	if (str2 == NULL)
		return (NULL);
	_strcpy(str2, str);
	return (str2);
}

/**
 * str_strlen - string lent
 * @str: string to determine the length
 * Return: the length of the string
 */
int str_strlen(char *str)
{
	int count;
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
char *str_strcpy(char *str2, const char *str)
{
	int count;

	while (str[i] == '\0')
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
char *str_strcat(char *str2, const char *str1)
{
	int i, j;

	i = 0, j = 0;
	for (; str2 != '\0'; i++)
		;
	for (; str1 != '\0'; j++)
	{
		str2[i] = str1[j];
		j++;
	}
	str2[j] = '\0';
	return (str2);
}
