#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void printer(const char *input);
void show_prompt(void);
void execute(char *input);
void read_input(char *input, size_t size);
size_t _strlen(const char *string);
char *get_line(void);

#endif /* SIMPLE_SHELL_H */
