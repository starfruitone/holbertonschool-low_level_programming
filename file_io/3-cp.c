#include "main.h"

static void handle_err(int code, const char *file, int fd)
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
	int src_fd, dst_fd, status;
	ssize_t n_read, n_written;
	char buffer[1024];

	if (argc != 3)
		handle_err(97, NULL, -1);

	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
		handle_err(98, argv[1], -1);

	dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dst_fd == -1)
	{
		close(src_fd);
		handle_err(99, argv[2], -1);
	}

	while ((n_read = read(src_fd, buffer, 1024)) > 0)
	{
		n_written = write(dst_fd, buffer, n_read);
		if (n_written == -1 || n_written != n_read)
		{
			close(src_fd);
			close(dst_fd);
			handle_err(99, argv[2], -1);
		}
	}

	if (n_read == -1)
	{
		close(src_fd);
		close(dst_fd);
		handle_err(98, argv[1], -1);
	}

	status = close(src_fd);
	if (status == -1)
		handle_err(100, NULL, src_fd);

	status = close(dst_fd);
	if (status == -1)
		handle_err(100, NULL, dst_fd);

	return (0);
}
