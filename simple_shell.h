#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void printer(const char *input);
void prompt_display(void);
void execute(const char *input);
void read_input(char *input, size_t size);
size_t _strlen(const char *string);

#endif /* SIMPLE_SHELL_H */
