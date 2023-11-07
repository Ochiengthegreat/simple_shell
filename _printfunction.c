#include "shell.h"
/*
 * @Koch_print - function that prints to STDOUT
 * @specialstring : the string to be printed to STDOUT
 */

void Koch_print(const char *specialstring)
{
	write(STDOUT_FILENO, specialstring, strlen(specialstring));
}
