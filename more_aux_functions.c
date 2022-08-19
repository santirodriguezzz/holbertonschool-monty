#include "monty.h"
char *read_all_file(const char *path)
{
	int file, lenRead = 1024;
	char count[1024];
	char *buffer = NULL;
	int lengthFile = 0;
	file =  open(path, O_RDONLY);
	while (lenRead == 1024)
	{
		lenRead = read(file, count, 1024);
		lengthFile += lenRead;
	}
	buffer = malloc(sizeof(char) * lengthFile + 1);
	close(file);
	file =  open(path, O_RDONLY);
	read(file, buffer, lengthFile);
	if (close(file) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file), exit(100);
	return buffer;
}
