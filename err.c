#include "main.h"
/**
 * c_error- creats an error
 * @arguments: the arguments of the program
 * @err: the error code
 * Return: the program output
 */
int c_error(char **arguments, int err)
{
	char *error;
	/*
	 * checks the error code
	*/
	switch (err)
	{
	case 126:
		if (1 == 1)
		error = error_126(arguments);
		break;
	case 127:
		if (1 == 1)
		error = error_127(arguments);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);

}
/**
 * error_126- error code 126
 * @arguments: the arguments of the program
 * Return: the error message
 */
char *error_126(char **arguments)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hs);
	if (!hist_str)
		return (N);

	len = _strlen(name) + _strlen(hist_str) + _strlen(arguments[0]) + 24;
	error = malloc(si(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (N);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, arguments[0]);
	_strcat(error, ": Permission denied\n");

	free(hist_str);
	return (error);
}

/**
 * error_127 - error for not finding the command.
 * @arguments: An array of arguments passed to the command.
 * Return: The error messeage.
 */
char *error_127(char **arguments)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hs);
	if (!hist_str)
		return (N);

	len = _strlen(name) + _strlen(hist_str) + _strlen(arguments[0]) + 16;
	error = malloc(si(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (N);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, arguments[0]);
	_strcat(error, ": not found\n");

	free(hist_str);
	return (error);
}
/**
 * _itoa - turns a number to string.
 * @num: the number to be transformed
 * Return: the string of the number
 */
char *_itoa(int num)
{
	char *buffer;
	int len = num_len(num);
	unsigned int num1;

	buffer = malloc(si(char) * (len + 1));
	if (!buffer)
		return (N);

	buffer[len] = '\0';

	if (num < 0)
	{
		num1 = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = num;
	}

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buffer);
}
/**
 * num_len - number of digits of the string
 * @x: the number to be counted
 * Return: the len
 */
int num_len(int x)
{

	int len = 0;

	if (x < 0)
		x *= -1;
	while (x)
	{
		len++;
		x /= 10;
	}
	return (len);
}
