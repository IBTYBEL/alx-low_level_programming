#include "main.h"

/**
 * read_textfile - reads a text file and prints it to standard output.
 * @filename: name of the file to read.
 * @letters: number of letters it should print.
 * Return: number of letters it could read and print.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t ch1, ch2;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	ch1 = read(fd, buffer, letters);
	if (ch1 == -1)
	{
		free(buffer);
		return (0);
	}
	ch2 = write(STDOUT_FILENO, buffer, ch1);
	if (ch2 == -1 || ch2 != ch1)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(fd);
	return (ch2);
}
