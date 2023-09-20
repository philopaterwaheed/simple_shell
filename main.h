#ifndef philo
#define philo
#define si(x) sizeof(x)
#define NT '\0'
 #include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "str.h"
#define N NULL
typedef struct builtin_
{
	char *nme;
	int (*f)(char **av, char **frnt);
} builtin_;
int t_len(char *strr, char *delim);
int c_tokens(char *strr, char *delim);
int proc_file_commands(char *file_path, int *exe_ret);
int unopenable(char *file_path);
int check_args(char **args);
void handle_line(char **line, ssize_t read);
ssize_t get_new_len(char *line);
int array_size(char **array);
void logical_ops(char *line, ssize_t *new_len);
int min(int x, int y);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
char **_getenv(const char *var);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int handle_args(int *exe_ret);
char *get_input(char *input, int *philo_retunn);
void *_memcpy(void *dest, void *src, unsigned int nbytes);
void *_realloc(void *ptr, unsigned int old, unsigned int new_);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream);
unsigned int is_delim(char c, char *delim);
char *my_strtok(char *srcString, char *delim);
char **_strtok(char *line, char *delim);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int exe(char **arguments, char **front);
char *get_args(char *line, int *exe_ret);
int handle_args(int *prog_return);
char *get_location(char *command);
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} linked_list;
void free_list(linked_list *head);
extern char **environ;
void free_arguments(char **args, char **front);
void free_env(void);
linked_list *add_node_end(linked_list **head, char *dir);
char *fill_path_dir(char *path);
char *error_126(char **args);
char *_itoa(int num);
int num_len(int x);
char *error_127(char **args);
char *_itoa(int num);
int c_error(char **args, int err);
linked_list *get_path_dir(char *path);
int (*get_builtinn(char *command))(char **args, char **front);
extern char *name;
char **_copyenv(void);
extern int hs;
int _env(char **arguments, char **first);
int _exit_(char **arguments, char **first);
#endif
