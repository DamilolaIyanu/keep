#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			return (1);
		}
	}
	if (child_pid == 0)
	{
		if (execve("/usr/bin/ls", argv, NULL) == -1);
		{
			perror("Error executing");
			exit(-1);
		}

	}
	else
	{
		wait(&status);
	}
	return (0);
}
