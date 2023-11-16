#include "shell.h"
/**
* _free - frees the argv memory
* @argv: memory to free
* @wc: word count
*/
void _free(char **argv, int wc)
{
	int i;

	for (i = 0; i < wc; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
