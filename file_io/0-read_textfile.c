#include "main.h"

/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: file to read
 * @letters: number of letters to read and print
 * Return: actual number of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buff;

	if (!filename || letters == 0)
		return (0);

	buff = malloc(letters);
	if (!buff)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buff);
		return (0);
	}

	bytes_read = read(fd, buff, letters);
	if (bytes_read == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buff, bytes_read);

	free(buff);
	close(fd);

	if (bytes_written != bytes_read)
		return (0);

	return (bytes_written);
}
