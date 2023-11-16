#ifndef _SHELL_H_
#define _SHELL_H_

/* System libraries needed */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/* shell functions */
void display_av(char *av[]);

void koch_print(const char *specialstring);

int word_count(char *str);

char *str_to_arr(char *str);

void tokenizer(char *str, char **dest);

void store_token(char *token, char **dest, int index);

void shell_exit(char *buffer);

char *get_path(char *command);

/* string functions */
char *_strcpy(char *dest, char *src);

int _strlen(char *s);

/* Advanced functions */
void handle_hash(char *buff);

char *_getline(void);

void *_realloc_(void *ptr, unsigned int old_size, unsigned int new_size);

char *_memcpy(char *dest, char *src, unsigned int n);

void *fill_array(void *ptr, int lx, unsigned int len);

#endif /* _SHELL_H_ */
