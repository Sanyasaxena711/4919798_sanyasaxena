#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char *isValid(char *s)
{
    static char yes[] = "YES";
    static char no[] = "NO";

    int freq[26] = {0};

    // count frequencies
    for (int i = 0; s[i]; i++)
    {
        freq[s[i] - 'a']++;
    }

    // collect only non-zero frequencies
    int f[26], f_count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            f[f_count++] = freq[i];
        }
    }

    // find min and max frequency
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < f_count; i++)
    {
        if (f[i] < min)
            min = f[i];
        if (f[i] > max)
            max = f[i];
    }

    if (min == max)
    {
        return yes; // already valid
    }

    int minCount = 0, maxCount = 0;
    for (int i = 0; i < f_count; i++)
    {
        if (f[i] == min)
            minCount++;
        if (f[i] == max)
            maxCount++;
    }

    // Case 1: One character occurs only once (frequency = 1)
    if (min == 1 && minCount == 1 && maxCount == f_count - 1)
    {
        return yes;
    }

    // Case 2: One character with frequency max = min+1
    if (max == min + 1 && maxCount == 1 && minCount == f_count - 1)
    {
        return yes;
    }

    return no;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char *s = readline();

    char *result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data)
        {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
        {
            data = '\0';
        }
    }
    else
    {
        data = realloc(data, data_length + 1);

        if (!data)
        {
            data = '\0';
        }
        else
        {
            data[data_length] = '\0';
        }
    }

    return data;
}
