#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	size_t buf_size = 10;
	char *buf = NULL;

	buf = malloc(sizeof(char) * 10);

	write(1, "Dammyshell$$ ", 13);
	getline(&buf, &buf_size, stdin);

	write(1, buf, strlen(buf));

	free(buf);
	
	return (0);
}
