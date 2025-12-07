#include "main.h"

/**
 * fail - prints an error message and exits with a given code
 * @code: exit status
 * @file: filename for read/write errors (can be NULL)
 * @fd: file descriptor for close error (or 0 when unused)
 */
static void fail(int code, char *file, int fd)
{
	if (code == 97)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	}
	else if (code == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	}
	else if (code == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	}
	else if (code == 100)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	}
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success, or exit with 97, 98, 99, 100 on error
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, close_status;
	ssize_t bytes_read = 1, bytes_written;
	char buff[1024];

	if (argc != 3)
		fail(97, NULL, 0);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		fail(98, argv[1], 0);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		fail(99, argv[2], 0);
	}

	while (bytes_read)
	{
		bytes_read = read(fd_from, buff, 1024);
		if (bytes_read == -1)
			fail(98, argv[1], 0);

		bytes_written = write(fd_to, buff, bytes_read);
		if (bytes_written == -1)
			fail(99, argv[2], 0);
	}

	close_status = close(fd_from);
	if (close_status == -1)
		fail(100, NULL, fd_from);

	close_status = close(fd_to);
	if (close_status == -1)
		fail(100, NULL, fd_to);

	return (0);
}

