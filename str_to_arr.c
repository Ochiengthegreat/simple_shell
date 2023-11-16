#include "shell.h"
/**
* str_to_arr - changes string to array
* @str: string to change
*
* Return: pointer to the array
*/
char *str_to_arr(char *str)
{
	int length = 0;

	char *arr;

	int i;

	length = _strlen(str);
	arr = malloc((length + 1) * sizeof(char));
	if (arr == NULL)
	{
		perror("Memory allocation");
		exit(1);
	}
	for (i = 0; i < length; i++)
	{
		arr[i] = str[i];
	}
	arr[i] = '\0';
	/* shell_exit(arr); */
	return (arr);
}
