#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

/** global variables*/
extern char **environ;
/**functions*/
int stringLength(char *str);
char *stringCopy(char *destination, char *source);
char *duplicateString(char *source);
void reverseString(char *str, int length);
char *stringConcatenate(char *destination, char *source);
char *integerToString(int number);
int countDigits(int num);
int stringToInteger(char *s);
char **tokenizeInput(char *buffer, ssize_t n, const char *delimiter);
char **getInputCommand();
void checkIfInteractiveShell(void);
int executeCommand(char **commandTokens, char *programName[]);
char *determineFinalCommand(char **commandTokens, char *programName[]);
void executeWithExecve(char *command, char **commandTokens,
char *programName[]);
int handleExitStatus(int status);
char *findEnvironmentVariable(char *varName);
void *printAllEnvironmentVariables(char **userCommand);
void processExitCommand(char **commandTokens);
void cleanupAndExit(char **commandTokens, int exitStatus);
char *constructFullPath(char **pathArray, char *command);
char *findExecutablePath(char *command);
int countPathTokens(char *path);
char *handleExecutionError(char *argv[], char **command);
void freeEnvironment(void);
void deallocateBuffer(char **buffer);
 
#endif
