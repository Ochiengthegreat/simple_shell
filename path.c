#include "main.h"
/**
 * get_path - function that takes in the cmd passed and returns
 * the path
 *
 * @command: string to be passed
 * Return: value of path
 *
 */

char *get_path(char *command)
{
	char *path, *path_dup, *ochieng_token, *file_path;
	int len_of_cmd, len_of_dir;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_dup = strdup(path);
		/* function gets length of the command */
		len_of_cmd = strlen(command);
		ochieng_token = strtok(path_dup, ":");

		while (ochieng_token != NULL)
		{
		/* Get the length of the directory*/
			len_of_dir = strlen(ochieng_token);
			file_path = malloc(len_of_cmd + len_of_dir + 2);
			strcpy(file_path, path_dup);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_dup);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_dup);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
