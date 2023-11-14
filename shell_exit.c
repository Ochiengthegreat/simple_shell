#include "shell.h"
/**
* shell_exit - logs out of the shell
* @buffer: string from stdin
*/
void shell_exit(char *buffer)
{
	char *str = "exit";

	buffer[4] = '\0';
	if (strcmp(str, buffer) == 0)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
}
