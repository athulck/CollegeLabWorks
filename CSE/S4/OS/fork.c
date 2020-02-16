/* Fork */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main() {

	
	int a=10, b=20;
	// printf("\n %d + %d = %d", a, b, a+b);
	printf("\nCalling Fork ... ");

	pid_t pid = fork();
	printf("\nPID : %d", pid);

	if (pid > 0) {
		printf("\nProcess ID of parent : %d", getpid());
		a = 30;
		printf("\n %d + %d = %d", a, b, a+b);

	} else if (pid == 0) {
		a = 40;
		printf("\nProcess ID of child : %d", getpid());
		printf("\n %d + %d = %d", a, b, a+b);
	
	} else printf("\nError !");


}
