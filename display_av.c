#include "shell.h"
/**
 * display_av - show contents of the string array
 * @av: array of strings
 *
 */
void display_av(char *av[])
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
}
