#include "shell.h"
/**
 * task1 - display shell prompt and execute one-word commands
 * @av1: first argument of the main program
 *
 */

void task1(char *av[])
{
	pid_t pid;
	ssize_t ret_getline;
	size_t n = 10;
	char *buffer;
	int status;


	buffer = malloc(sizeof(char) * 10);
	write(stdin, "#cisfun ", 9);
	ret_getline = getline(&buffer, &n, stdin);
	pid = fork();
	if (pid == -1)
		printf("Fork Error");
	if (pid == 0)
	{
		if (execve(av[1], av, NULL) == -1)
			perror("Error: ");
	}
	else
	{
		wait(&status);
	}
}
