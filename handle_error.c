#include "shell.h"
/**
* handleExecutionError- checks for errors and sets the error_message
* variable accordingly. If an error is detected, it returns an error
* message as a string.
* @argv: an array that holds the command-line arguments.
* @command: command that will be checked for displaying errors.
* Return: a pointer pointing to the error
*/
char *handleExecutionError(char *argv[], char **command)
{
    char *name;

    int name_len;

    int length_of_command, counter = 1;

    char *line_num, *error;

    int error_len, total_length;

    name = argv[0];
    name_len = stringLength(name);
    length_of_command = stringLength(command[0]);
    line_num = integerToString(counter);
    total_length = name_len +  length_of_command
+ stringLength(line_num) + 17;
    error = malloc(total_length + 1);
    if (error == NULL)
    {
        return (NULL);
    }
    stringCopy(error, name);
    stringConcatenate(error, ": ");
    stringConcatenate(error, line_num);
    stringConcatenate(error, ": ");
    stringConcatenate(error, command[0]);
    stringConcatenate(error, ": not found\n");
    free(line_num);
    error_len = stringLength(error);
    write(STDERR_FILENO, error, error_len);
    return (error);
}
