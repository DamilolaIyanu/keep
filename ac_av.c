#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("argument %d is %s\n", i, av[i]);
		i++;
	}
	return (0);
}
