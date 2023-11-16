#include "shell.h"
/**
* _getline - Read input from stdin
* Return: A line of input, NULL on failure
*/
char *_getline(void)
{
	size_t buf_size = 1024;
	char *buff = malloc(buf_size);
	ssize_t rd;
	int i;

	if (buff == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0;; i++)
	{
		rd = read(STDIN_FILENO, &buff[i], 1);
		if (rd == -1)
		{
			perror("read");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (rd == 0 || buff[i] == '\n')
		{
			buff[i] = '\0';
			break;
		}
		if (i >= (int)buf_size - 1)
		{
			char *new_buff = _realloc_(buff, buf_size, buf_size + 1024);

			if (new_buff == NULL)
			{
				perror("realloc");
				free(buff);
				exit(EXIT_FAILURE);
			}
			buff = new_buff;
			buf_size += 1024;
		}
	}
	handle_hash(buff);
	return (buff);
}
/**
* handle_hash - Remove everything after #
* @buff: Input string
*
*/
void handle_hash(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
