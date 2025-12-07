#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, or exits with error codes 97, 98, 99, 100
 */
static void handle_error(int code, char *file, int fd)
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

int main(int argc, char **argv)
{
	int fd_from, fd_to, c_status;
	ssize_t bytes_read, bytes_written;
	char buf[1024];

	if (argc != 3)
		handle_error(97, NULL, 0);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		handle_error(98, argv[1], 0);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		handle_error(99, argv[2], 0);
	}

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd_from, buf, 1024);
		if (bytes_read == -1)
			handle_error(98, argv[1], 0);

		bytes_written = write(fd_to, buf, bytes_read);
		if (bytes_written == -1)
			handle_error(99, argv[2], 0);
	}

	c_status = close(fd_from);
	if (c_status == -1)
		handle_error(100, NULL, fd_from);

	c_status = close(fd_to);
	if (c_status == -1)
		handle_error(100, NULL, fd_to);

	return (0);
}
