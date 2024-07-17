#include "shell.h"

/**
* info_init - This initializes info_t struct
* @info: This is struct address
*/
void info_init(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
* info_set - This initializes info_t struct
* @info: This is struct address
* @av: The argument vector
*/
void info_set(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_token_aliass(info);
		replace_variables_info(info);
	}
}

/**
* info_release -  This frees info_t struct fields
* @info: This struct address
* @all:This is true if freeing all fields
*/
void info_release(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			release_listt(&(info->env));
		if (info->history)
			release_listt(&(info->history));
		if (info->alias)
			release_listt(&(info->alias));
		ffree(info->environ);
		info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
