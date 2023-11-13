#include "shell.h"
/**
* tokenizer - demostrating tokenization
* @str: string to tokenize
* @dest: **argv
*
*/
void tokenizer(char *str, char **dest)
{
	char *token;

	int index = 0;

	token = strtok(str, "\t\n ");
	while (token != NULL)
	{
		store_token(token, dest, index);
		index++;
		token = strtok(NULL, "\t\n ");
	}
	dest[index] = NULL;
}
