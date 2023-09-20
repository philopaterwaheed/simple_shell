#include "main.h"
/**
 * _memcpy - copy @nbytes bytes from @src to @dest
 * @dest: pointer to start writting to
 * @src: pointer to start reading from
 * @nbytes: number of bytes to be copied
 *
 * Return: @dest on success otherwise NULL on fail
 */
void *_memcpy(void *dest, void *src, unsigned int nbytes)
{
	void *org = dest;
	size_t i;

	for (i = 0; i < nbytes; i++)
		((char *)dest)[i] = ((char *)src)[i];
	return (org);
}
/**
 * _realloc - realloc implementation
 * @ptr: newwory allocated.
 * @old: space
 * @new_: new newwory
 * Return: meomery
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new_)
{
	void *neww;

	if (ptr == N)
		return (malloc(new_));
	if (new_ == 0)
	{
		free(ptr);
		return (N);
	}
	if (old == new_)
		return (ptr);
	neww = malloc(new_);
	if (!neww)
		goto end;
	new_ = min(old, new_);
	_memcpy(neww, ptr, min(old, new_));
	free(ptr);
	return (neww);
end:
	free(ptr);
	return (N);
}
/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == N)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _get_line - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(si(char) * 120);
	if (!buffer)
		return (-1);
	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	assign_lineptr(lineptr, n, buffer, input);
	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}

