#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* For read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* For command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* This is for convert_number() - constants defined */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - This is the singly linked list
 * @num: this is the number field
 * @str: This is a string
 * @next: This points to the next node
 */
typedef struct liststr
{
    int num;
    char *str;
    struct liststr *next;
} list_t;

/**
 * struct passinfo - This contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: string path for the current command
 * @argc:This is the argument count
 * @line_count: This is the error count
 * @err_num: This is the error code for exit()s
 * @linecount_flag: This is if on count this line of input
 * @fname: This is the program filename
 * @env: This is the linked list local copy of environ
 * @environ: Thsi is the custom modified copy of environ from LL env
 * @history: This the history node
 * @alias: This the alias node
 * @env_changed: This is on if environ was changed
 * @status: This is the return status of the last exec'd command
 * @cmd_buf: This is an address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type:The  CMD_type ||, &&, ;
 * @readfd: This the fd from which to read line input
 * @histcount: This is the history line number count
 */
typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;

    char **cmd_buf;   /* pointer to cmd ; chain buffer, for memory mangement */
    int cmd_buf_type; /* CMD_type ||, &&, ; */
    int readfd;
    int histcount;
} info_t;

#define INFO_INIT                                                               \
    {                                                                           \
        NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
            0, 0, 0                                                             \
    }

/**
 * struct builtin - This contains a builtin string and related function
 * @type: This is the builtin command flag
 * @func: This is the function
 */
typedef struct builtin
{
    char *type;
    int (*func)(info_t *);
} builtin_table;

/* fuc_in__shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* fuc_in__parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* fuc_in__errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* fuc_in__string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* fuc_in__string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* fuc_in__exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* fuc_in__tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* fuc_in__realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* fuc_in__memory.c */
int bfree(void **);

/* fuc_in__atoi.c */
int interactive(info_t *);
int is_delimeter(char c, char *delim);
int _isalpha(int);
int _atoi(char *);

/* fuc_in__errors1.c */
int _str_atoi(char *);
void print_error_msg(info_t *, char *);
int print_dec(int, int);
char *convert_number_c(long int, int, int);
void comment_remover(char *);

/* fuc_in__builtin.c */
int _myexxit(info_t *);
int _myccd(info_t *);
int _myheelp(info_t *);

/* fuc_in__builtin1.c */
int _myhistoryy(info_t *);
int _myaliass(info_t *);

/*fuc_in__getline.c */
ssize_t input_buffer_cmd(info_t *info, char **buf, size_t *len);
ssize_t get_input_cmd(info_t *);
ssize_t read_buffer_cmd(info_t *info, char *buf, size_t *i);
int _getline(info_t *, char **, size_t *);
void sigint_Handler(int);

/* fuc_in__getinfo.c */
void info_init(info_t *);
void info_set(info_t *, char **);
void info_release(info_t *, int);

/* fuc_in__environ.c */
char *_getenv(info_t *, const char *);
int _my_environment(info_t *);
int _my_setenv(info_t *);
int _my_unsetenv(info_t *);
int calculate_env_list(info_t *);

/* fuc_in__getenv.c */
char **get_environment(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* fuc_in__history.c */
char *get_historry_files(info_t *info);
int write_historry(info_t *info);
int read_historry(info_t *info);
int build_historry(info_t *info, char *buf, int linecount);
int renumber_historry(info_t *info);

/* fuc_in__lists_a.c */
list_t *add_nodee_begining(list_t **, const char *, int);
list_t *add_nodee_end(list_t **, const char *, int);
size_t print_listt_str(const list_t *);
int delete_nodee_at_index(list_t **, unsigned int);
void release_listt(list_t **);

/* fuc_in__lists_b.c */
size_t listt_length(const list_t *);
char **listt_of_strings(list_t *);
size_t printt_lists(const list_t *);
list_t *startt_node_is(list_t *, char *, char);
ssize_t gett_node_index(list_t *, list_t *);

/* fuc_in__vars.c */
int iss_chain_delim(info_t *, char *, size_t *);
void delim_check(info_t *, char *, size_t *, size_t, size_t);
int replace_token_aliass(info_t *);
int replace_variables_info(info_t *);
int replace_string_info(char **, char *);

#endif
