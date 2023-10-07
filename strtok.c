#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int n;
	size_t buf_size = 1024;
	char *buf;
	char *input;
	const char *delim = " \t\b";
	char *tokens;

	buf = (char *)malloc(sizeof(char) * buf_size);
	if (buf == NULL)
	{
		perror("malloc failed");
		return (1);
	}

	write(1, "Dammyshell$$ ", 13);
	n = getline(&buf, &buf_size, stdin);

	if (n == -1)
	{
		perror("getline failed");
		free(buf);
		return 1;
	}

	input = buf;
	tokens = strtok(input, delim);

	while (tokens != NULL)
	{
		write(1, tokens, strlen(tokens));
		tokens = strtok(NULL, delim);
		if (tokens)
			write(1, "\n", 1);
	}

	free(buf);
	
	return (0);
}
