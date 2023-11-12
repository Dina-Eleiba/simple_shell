#include "shell.h"

/**
* integerToString - Convert an integer to a string.
* @number: The integer to be converted.
* Return: A pointer to the resulting string or NULL on failure.
*/

char *integerToString(int number)
{
    char *stringBuffer;

    int length = countDigits(number);

    int index = 0, isNegative = 0, digit, start, end;

    stringBuffer = malloc(sizeof(char) * (length + 2));
    if (stringBuffer == NULL)
    {
        return (NULL);
    }

    if (number < 0)
    {
        isNegative = 1;
        number = -number;
        stringBuffer[index] = '-';
        index++;
    }

    if (number == 0)
    {
        stringBuffer[index] = '0';
        index++;
    }
    else
    {
        while (number > 0)
        {
            digit = number % 10;
            stringBuffer[index] = digit + '0';
            number = number / 10;
            index++;
        }
    }
    start = isNegative ? 1 : 0;
    end = index - 1;
    reverseString(stringBuffer + start, end);
    stringBuffer[index] = '\0';
    return (stringBuffer);
}

/**
* countDigits - Count the number of digits in an integer.
* @num: The integer to count digits for.
* Return: The number of digits.
*/

int countDigits(int num)
{
    int count = 0;

    while (num != 0)
    {
        num = num / 10;
        count++;
    }

    return (count);
}

/**
* stringToInteger - Convert a string to an integer.
* @s: The pointer to the string.
* Return: The converted integer value.
*/

int stringToInteger(char *s)
{
    int number = 0;

    int index = 0;

    int sign = 1;

    while (s[index] != '\0')
    {
        if (s[index] == '-')
        {
            sign *= -1;
            index++;
        }
        else if (s[index] >= '0' && s[index] <= '9')
        {
            number *= 10;
            number += s[index] - '0';
            index++;
        }
        else
        {
            break;
        }
    }

    return (number * sign);
}
