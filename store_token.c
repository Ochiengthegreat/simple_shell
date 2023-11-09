#include "shell.h"
/**
* store_token - stores token to string array
* @token: string to store
* @dest: ** argv
* @index: index address of string in array
*/
void store_token(char *token, char **dest, int index)
{
	int length = 0;

	length = strlen(token);
	dest[index] = malloc(sizeof(char) * (length + 1));
		if (dest[index] == NULL)
		{
			perror("Memory Allocation");
			exit(1);
		}
	strcpy(dest[index], token);
}
