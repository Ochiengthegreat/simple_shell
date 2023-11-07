#include "shell.h"
/**
 * main - Entry point of simple shell
 *
 * Return: Always 0 on success
 */
int main(void)
{
    pid_t child_pid;
    size_t buf_size = 0;
    char *buffer = NULL;
    char *token;
    int status, i = 0;
    char **argv;

    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);
        getline(&buffer, &buf_size, stdin);
        token = strtok(buffer, "\t\n");
        argv = malloc(sizeof(char *) * 1024);
        while (token)
        {
            argv[i] = token;
            token = strtok(NULL, "\t\n");
            i++;
        }
        argv[i] = NULL;
        child_pid = fork();
        if (child_pid == 0)
        {
            if (execve(argv[0], argv, NULL) == -1)
                perror("Error");
        }
        else
        {
            wait(&status);
        }
        i = 0;
        free(argv);
    }
}
