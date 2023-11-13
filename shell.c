#include "shell.h"
/**
* main - test case
*
* Return: Always 0(success)
*/
int main(void)
{
	pid_t child_pid;
	size_t buf_size = 0;
	char *buffer = NULL;
	int wc = 0;
	char *arry;
	char **argv = NULL;
	int status = 0;
	int counter = 0;

	while (1)
	{
		if (counter > 1)
			free(argv);
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		getline(&buffer, &buf_size, stdin);
		wc = word_count(buffer);
		argv = malloc(sizeof(char *) * (wc + 1));
		if (argv == NULL)
		{
			perror("Memory Allocation");
			exit(1);
		}
		arry = str_to_arr(buffer);
		tokenizer(arry, argv);
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
