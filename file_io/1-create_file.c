#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)



{
	int fd, status = 1;
	ssize_t len = 0, written;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (len > 0)
	{
		written = write(fd, text_content, len);
		if (written == -1 || written != len)
			status = -1;
	}

	if (close(fd) == -1)
		status = -1;

	return (status);
}
