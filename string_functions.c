#include "shell.h"

/**
* stringLength - Calculate the length of a string.
* @str: Pointer to the input string.
* Return: The length of the string.
*/

int stringLength(char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

/**
* stringCopy - Copy the content of one string to another.
* @destination: The destination string.
* @source: The source string to copy from.
* Return: The destination string after copying.
*/

char *stringCopy(char *destination, char *source)
{
    int index;
    int sourceLength = stringLength(source);

    for (index = 0; source[index] != '\0' && index < sourceLength; index++)
    {
        destination[index] = source[index];
    }

    destination[index] = '\0';

    return destination;
}

/**
* duplicateString - Create a duplicate of a string.
* @source: The string to be duplicated.
* Return: A new dynamically allocated copy of the input string.
*/

char *duplicateString(char *source)
{
    size_t length;
    char *copyString;

    if (source == NULL)
    {
        return NULL;
    }

    length = stringLength(source);

    copyString = malloc(sizeof(char) * (length + 1));

    if (copyString == NULL)
    {
        return NULL;
    }

    stringCopy(copyString, source);

    return copyString;
}

/**
* reverseString - Reverse the characters in a string.
* @str: The string to be reversed.
* @length: The length of the string.
*/

void reverseString(char *str, int length)
{
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

/**
* stringConcatenate - Concatenate two strings.
* @destination: The first string.
* @source: The string to be added.
* Return: The concatenated string.
*/

char *stringConcatenate(char *destination, char *source)
{
    int i, j;

    i = 0;
    while (destination[i] != '\0')
    {
        i++;
    }

    j = 0;
    while (source[j] != '\0')
    {
        destination[i] = source[j];
        i++;
        j++;
    }

    destination[i] = '\0';    
    return destination;
}
