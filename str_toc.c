#include "main.h"
#include "str.h"
#include <string.h>
/**
 * is_delim - checks if it is a delim or not
 * @c: The character to be checked.
 * @delim: The delimiter character.
 * Return: The number of words contained within str.
 * not used yet
 */
unsigned int is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}
/**
 * my_strtok - for my own tokinizing
 * @line: The string to be searched.
 * @delim: The delimiter character.
 * Return: The number of words contained within str.
 * not used yete
 */
char *my_strtok(char *line, char *delim)
{
	int j;
	static char *strr;
	char *copystr;

	if (line != N)
		strr = line;
	for (; *strr != '\0'; strr++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*strr == delim[j])
			break;
		}
		if (delim[j] == '\0')
			break;
	}
	copystr = strr;
	if (*copystr == '\0')
		return (N);
	for (; *strr != '\0'; strr++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*strr == delim[j])
			{
				*strr = '\0';
				strr++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
int t_len(char *strr, char *delim)
{
	int idx = 0, len = 0;

	while (*(strr + idx) && *(strr + idx) != *delim)
	{
		len++;
		idx++;
	}

	return (len);
}

/**
 * c_tokens - Counts the number of tokens
 * @strr: The string to be searched.
 * @delim: The delimiter character.
 * Return: The number of words contained within str.
 */
int c_tokens(char *strr, char *delim)
{
	int idx, tokens = 0, len = 0;

	for (idx = 0; *(strr + idx); idx++)
		len++;

	for (idx = 0; idx < len; idx++)
	{
		if (*(strr + idx) != *delim)
		{
			tokens++;
			idx += t_len(strr + idx, delim);
		}
	}
	return (tokens);
}
/*
char **_strtokchar *line, char *delim)
{
	char **args = N;
	int len, i, j, counter =2;

	len = _strlen(line);
	if (len)
		{
			if (line [len -1] == '\n')
				line [len -1] = '\0';
		}	
	
	for (i = 0; line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				counter++;
		}
	}
	args = malloc(si(char*) * counter);
	if (args == N)
	{
		handle errors 
	}
	i=0;
	args[i] = strdup (my_strtok(line, delim));
	while (args[++i] != N) {
	write(STDOUT_FILENO, "philo ",1);
	args[i] = strdup(my_strtok(line, delim));
	}
return (args);
}
*/
/**
 * _strtok - tokinizing the string inputed
 * @line: the string to be toknized.
 * @delim: The delimiter character.
 * Return: The number of words contained within str.
 */
char **_strtok(char *line, char *delim)
{
	char **ptr;
	int idx = 0, tokens, t, let, l;

	tokens = c_tokens(line, delim);
	if (tokens == 0)
		return (N);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (N);

	for (t = 0; t < tokens; t++)
	{
		while (line[idx] == *delim)
			idx++;

		let = t_len(line + idx, delim);

		ptr[t] = malloc(sizeof(char) * (let + 1));
		if (!ptr[t])
		{
			for (idx -= 1; idx >= 0; idx--)
				free(ptr[idx]);
			free(ptr);
			return (N);
		}

		for (l = 0; l < let; l++)
		{
			ptr[t][l] = line[idx];
			idx++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = N;
	ptr[t + 1] = N;

	return (ptr);
}
