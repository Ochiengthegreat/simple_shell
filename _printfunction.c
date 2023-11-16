#include "shell.h"
/**
* koch_print - the function that prints to STDOUT
* @str: string to print
*
*/
void koch_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
