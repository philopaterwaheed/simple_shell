#include "main.h"
/**
 * _strcat - add a string to anthorer
 * @destination: to be added to @src
 * @srcoure: to be adeed to @destination
 * Return: destination
 */
char *_strcat(char *destination, const char *srcoure)
{
	char *destTmp;
	const char *srcTmp;

	destTmp = destination;
	srcTmp =  srcoure;

	while (*destTmp != '\0')
		destTmp++;

	while (*srcTmp != '\0')
		*destTmp++ = *srcTmp++;
	*destTmp = '\0';
	return (destination);
}
/**
 * _strncat - addes only n to the string
 * @destination: to be added to destination
 * @src: to be appended to destination
 * @n: the amunt
 */
char *_strncat(char *destination, const char *src, size_t n)
{
	
	size_t dest_ln = _strlen(destination);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		destination[dest_ln + i] = src[i];
	destination[dest_ln + i] = '\0';

	return (destination);
}
/**
 * str_duplicate - repredios a sting to a one like it
 * @string: to be added to destination
 */
char *str_duplicate(char *string)
{
	char *result;
	int length, i;

	if (string == N)
		return (N);

	length = _strlen(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == N)
	{
		errno = ENOMEM;
		perror("Error");
		return (N);
	}
	for (i = 0; i < length ; i++)
	{
		result[i] = string[i];
	}

	return (result);
}
