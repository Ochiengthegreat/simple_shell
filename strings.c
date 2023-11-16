#include "shell.h"
/**
* _strcpy - copies a string from one destination to another using pinters
* @src: pointer to string being copied
* @dest: pointer to destination of copy
*
* Return: dest
*/
char *_strcpy(char *dest, char *src)
{
	int i, j;

	i = 0;

	while (*src != '\0')
	{
		i++;
		src++;
	}

	for (j = 0; j < i; j++)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return (dest);
}
#include "shell.h"
/**
* _strlen - calculates the length of a string
* @s: pointer to string
*
* Return: length of string
*/
int _strlen(char *s)
{
	int i;

	i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
