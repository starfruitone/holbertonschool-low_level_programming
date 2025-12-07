#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, or exits with error codes 97, 98, 99, 100
 */
static char *get_buf(const char *to)
{
	char *buf = malloc(1024);

	if (!buf)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
		exit(99);
	}
	return (buf);
}

static void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

int main(int argc, char **argv)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = get_buf(argv[2]);
	fd_from = open(argv[1], O_RDONLY);
	r = read(fd_from, buf, 1024);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	do {
		if (fd_from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		w = write(fd_to, buf, r);
		if (fd_to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		r = read(fd_from, buf, 1024);
		fd_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(buf);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
