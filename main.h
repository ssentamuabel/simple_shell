#ifndef MAIN_H
#define MAIN_H

/* header files */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<signal.h>


/* function prototypes */
int _putchar(char c);
int _puts(char *str);
char *prompt(void);
void execmd(char **args);
char *get_location(char *command);

#endif
