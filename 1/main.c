#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_WIDTH 128

int spelled_nbr(char **input)
{
	char *nbr[] = {
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
	};

	for (int i = 0; i < 9; ++i)
	{
		if (!strncmp(nbr[i], *input, strlen(nbr[i])))
		{
			*input += strlen(nbr[i]) - 2;
			return i + 1;
		}
	}
	return 0;
}

int to_nbr(char *input)
{
	int res = -1;
	int curr_digit = 0;
	int last_digit = -1;

	while (*input)
	{
		curr_digit = isdigit(*input) ? *input - '0' : spelled_nbr(&input);
		if (curr_digit)
		{
			if (res < 0)
				res = 10 * curr_digit;
		 last_digit = curr_digit;
		curr_digit = 0;
		}
		++input;
	}
	if (last_digit < 0)
		return (0);
	res += last_digit;
	return res;
}

int main( void )
{
	FILE *fp;
	char *line;
	size_t	n = LINE_WIDTH;
	size_t res = 0;

	if (!(fp = fopen("./input.txt", "r")) || !(line = malloc(LINE_WIDTH)))
		exit(EXIT_FAILURE);
	while(getline(&line, &n, fp) > 0)
	{
		res += to_nbr(line);
	}
	printf("%lu", res);
	return (EXIT_SUCCESS);
}
