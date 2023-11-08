#include "shell.h"
/*
 * @koch_print : the function that prints to STDOUT
 * @specialstring : the string to be printed to STDOUT
 */

void koch_print(const char *specialstring)
{
	write(STDOUT_FILENO, specialstring, strlen(specialstring));
}
