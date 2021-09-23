#include "monty.h"

/**
 *main - dkjaapoodkqpaslñd
 *@argc: odjkflkdmlmd
 *@argv: djksdfksdmsdc
 *Return: lkcmlmkclksmdc
 */
int main(int argc, char **argv)
{
	char buffer[1024], t[1024] = "", *tok = t;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	save.fp = fopen(argv[1], "r");
	if (!(save.fp))
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
			argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), save.fp))
	{
		tok = strtok(buffer, " \t");
		if (tok[0] == '#')
			nop(&stack, linenumber);
		else if (tok[0] != '\n')
			switch_s(&stack, tok, linen_umber)(&stack,
				   linen_umber);
		line_number++;
	}
	free_all(&stack);
	return (EXIT_SUCCESS);
}
