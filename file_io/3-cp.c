#include "main.h"

/**
 * print_error - print error message and exit with the given code
 * @code: exit status
 * @file: filename (for 98/99) or NULL
 * @fd: file descriptor (for 100) or -1
 */
static void print_error(int code, const char *file, int fd)
{
	if (code == 97)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	else if (code == 98)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	else if (code == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	else if (code == 100)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with 97/98/99/100 on error
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, c;
	ssize_t r, w;
	char buf[1024];

	if (argc != 3)
		print_error(97, NULL, -1);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, argv[1], -1);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error(99, argv[2], -1);
	}

	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			print_error(99, argv[2], -1);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error(98, argv[1], -1);
	}

	c = close(fd_from);
	if (c == -1)
		print_error(100, NULL, fd_from);

	c = close(fd_to);
	if (c == -1)
		print_error(100, NULL, fd_to);

	return (0);
}
