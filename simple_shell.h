#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

extern char **environ;
void printer(const char *input);
void show_prompt(void);
void execute(char *input, char **environ);
void read_input(char *input, size_t size);
size_t _strlen(const char *string);
char *get_line(void);
void _tokenize(char *line, const char *delim, char *arg[], int max_token);
void test_path(char *path, char *command, char fullpath[]);
void _env(char **environ);
void exit_cmd(void);
void cd(char *dir);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strchr(const char *path, int c);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif /* SIMPLE_SHELL_H */
