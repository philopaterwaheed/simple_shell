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
	while (*delim != NT)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
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
	for (; *strr != NT; strr++)
	{
		for (j = 0; delim[j] != NT; j++)
		{
			if (*strr == delim[j])
			break;
		}
		if (delim[j] == NT)
			break;
	}
	copystr = strr;
	if (*copystr == NT)
		return (N);
	for (; *strr != NT; strr++)
	{
		for (j = 0; delim[j] != NT; j++)
		{
			if (*strr == delim[j])
			{
				*strr = NT;
				strr++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
/**
 * t_len- tokinizing the string inputed
 * @strr: the string to be toknized.
 * @delim: The delimiter character.
 * Return: The number of words contained within str.
 */
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

	ptr = malloc(si(char *) * (tokens + 2));
	if (!ptr)
		return (N);

	for (t = 0; t < tokens; t++)
	{
		while (line[idx] == *delim)
			idx++;

		let = t_len(line + idx, delim);

		ptr[t] = malloc(si(char) * (let + 1));
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

		ptr[t][l] = NT;
	}
	ptr[t] = N;
	ptr[t + 1] = N;

	return (ptr);
}
