#include "main.h"
/**
 * array_size - length of an array of char**
 * @array: the string.
 * Return: length the array best i could get acually.
 */
int array_size(char **array)
{
	int size = 0;

	while (array[size] != N)
	{
		size++;
	}
	return (size);
}

