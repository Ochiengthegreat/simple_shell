#include "shell.h"
/**
* word_count - counts the number of words
* @str: string to be counted
*
* Return: word count
*/
int word_count(char *str)
{
	char *holder;

	char *token;

	int i = 0;

	int len = 0;

	len = _strlen(str);
	holder = malloc(sizeof(char) * (len + 1));
	if (holder == NULL)
	{
		perror("Memory allocation");
		exit(1);
	}
	_strcpy(holder, str);
	token = strtok(holder, " ");
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, " ");
	}
	return (i);
}
