#include "monty.h"

int main(int argc, char **argv)
{
	char *file_content;
	int line_num;
	char *opcode = NULL;
	stack_t *stack = NULL;

	if (argc > 1)
	{
		file_content = read_all_file(argv[1]);
		printf("%s\n", file_content);
	}
return 0;

} 
