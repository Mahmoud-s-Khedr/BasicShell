#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
int main()
{

    while (1) {
	printf("$ ");

	char cmd[1024];
	scanf("%s", cmd);
	if (strcmp(cmd, "exit") == 0)
	    break;
	int pid = fork();
	if (pid == 0) {
	    execlp(cmd, cmd, NULL);
	} else {
	    wait(NULL);
	}

    }

    return 0;
}
