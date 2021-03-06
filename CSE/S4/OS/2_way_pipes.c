#include<stdio.h>
#include<unistd.h>

void main() {
   
   int pipefds1[2], pipefds2[2];
   
   int pid;
   char pipe1writemessage[20] = "Hi";
   char pipe2writemessage[20] = "Hello";
   char readmessage[20];
   
   
   
   if (pipe(pipefds1) == -1) {
      printf("\nUnable to create pipe 1 !");
   }
   
   if (pipe(pipefds2) == -1) {
      printf("\nUnable to create pipe 2 !");
   }
   
   pid = fork();
   
   if (pid > 0) {
      
      close(pipefds1[0]); // Close the unwanted pipe1 read side
      close(pipefds2[1]); // Close the unwanted pipe2 write side
      printf("In Parent: Writing to pipe 1 – Message is %s\n", pipe1writemessage);
      write(pipefds1[1], pipe1writemessage, sizeof(pipe1writemessage));
      read(pipefds2[0], readmessage, sizeof(readmessage));
      printf("In Parent: Reading from pipe 2 – Message is %s\n", readmessage);
   } else { //child process
      close(pipefds1[1]); // Close the unwanted pipe1 write side
      close(pipefds2[0]); // Close the unwanted pipe2 read side
      read(pipefds1[0], readmessage, sizeof(readmessage));
      printf("In Child: Reading from pipe 1 – Message is %s\n", readmessage);
      printf("In Child: Writing to pipe 2 – Message is %s\n", pipe2writemessage);
      write(pipefds2[1], pipe2writemessage, sizeof(pipe2writemessage));
   }
   return 0;
}



SEPM group:
1.Amith Abraham Rajan
2.Athul C K
3.Savio Rajan
4.Steve Waltin
5.Tom Joseph
6.Ryan Thomas
7.Amal Saju K
8.Aneesha Kunjmon
9.Arunima Vijayan