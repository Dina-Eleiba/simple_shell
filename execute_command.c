#include "shell.h"

/**
* executeCommand - Execute a command.
* @commandTokens: Array of command tokens to execute.
* @programName: The name of the program.
* Return: Exit status.
*/

int executeCommand(char **commandTokens, char *programName[])
{
    pid_t childProcess;
    char *finalCommand;
    int status, exitStatus;

    finalCommand = determineFinalCommand(commandTokens, programName);
    if (finalCommand)
    {
        childProcess = fork();
        if (childProcess == -1)
        {
            return (-1);
        }
        if (childProcess == 0)
        {
            executeWithExecve(finalCommand, commandTokens, programName);
        }
        else if (childProcess > 0)
        {
            waitpid(childProcess, &status, WUNTRACED);
            while (!WIFEXITED(status) && !WIFSIGNALED(status))
            {
                waitpid(childProcess, &status, WUNTRACED);
            }
            exitStatus = handleExitStatus(status);
        }
    }
    return (exitStatus);
}

/**
* determineFinalCommand - Determine the final command to execute.
* @commandTokens: Array of command tokens.
* @programName: The name of the program.
* Return: The final command to execute.
*/

char *determineFinalCommand(char **commandTokens, char *programName[])
{
    char *command = commandTokens[0];
    char *finalCommand;
    char *error;

    if (commandTokens == NULL || commandTokens[0] == NULL)
    {
        return (NULL);
    }

    if (command[0] != '/' && command[0] != '.')
    {
        finalCommand = findExecutablePath(command);
        if (finalCommand == NULL)
        {
            error = handleExecutionError(programName, commandTokens);
            if (error == NULL)
            {
                deallocateBuffer(commandTokens);
            }
            exit(127);
        }
    }
    else
    {
        finalCommand = command;
    }
    return (finalCommand);
}
