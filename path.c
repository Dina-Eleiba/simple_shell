#include "shell.h"

/**
* findExecutablePath - Retrieve the full path of a
* command from environment variables.
* @command: The command to locate.
* Return: The full path to the command or NULL if not found.
*/

char *findExecutablePath(char *command)
{
    char *pathVariable;

    char **pathArray;

    const char *delimiter = ":";

    char *fullPath = NULL;

    char *pathCopy;

    int num = 0;

    pathVariable = getenv("PATH");
    if (pathVariable == NULL)
    {
        return (NULL);
    }
    num = countPathTokens(pathVariable);
    pathCopy = malloc(stringLength(pathVariable) + 1);
    stringCopy(pathCopy, pathVariable);

    pathArray = tokenizeInput(pathCopy, num, delimiter);
    free(pathCopy);
    fullPath = constructFullPath(pathArray, command);
    deallocateBuffer(pathArray);
    return (fullPath);
}

/**
* constructFullPath - Build the full path for a command.
* @pathArray: An array of directories in the PATH.
* @command: The command to append to the path.
* Return: The full path to the command or NULL if not found.
*/

char *constructFullPath(char **pathArray, char *command)
{
    int i;

    struct stat fileStatus;
    char *fullPath;

    int totalLength;

    char *separator = "/";

    int commandLength = stringLength(command);

    for (i = 0; pathArray[i] != NULL; i++)
    {
        int pathLength = stringLength(pathArray[i]);

        totalLength = pathLength + commandLength + 2;
        fullPath = malloc(totalLength);
        if (fullPath == NULL)
        {
            return (NULL);
        }
        stringCopy(fullPath, pathArray[i]);
        stringConcatenate(fullPath, separator);
        stringConcatenate(fullPath, command);

        if (stat(fullPath, &fileStatus) == 0
	&& access(fullPath, X_OK) == 0)
        {
            return (fullPath);
        }
        else
        {
            free(fullPath);
        }
    }
    return (NULL);
}

/**
* countPathTokens - Count the number of tokens in the PATH.
* @path: The PATH environment variable.
* Return: The number of tokens.
*/

int countPathTokens(char *path)
{
    char *pathCopy;

    int tokenCount = 0;

    char *token;

    const char *delimiter = ":";

    pathCopy = duplicateString(path);
    token = strtok(pathCopy, delimiter);
    while (token != NULL)
    {
        tokenCount++;
        token = strtok(NULL, delimiter);
    }
    free(pathCopy);

    return (tokenCount);
}
