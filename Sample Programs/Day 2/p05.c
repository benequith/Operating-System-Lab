/* creation of a process with fork()  
Understand existence of zombie process*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  pid_t pid;
  printf("Parent Process Id: %d\n",getpid());
  pid=fork();

  if (pid==0) { /* child process */
   printf("Child Process Id: %d and my Parent Process Id: %d \n",getpid(), getppid());
   exit(0); // child made to exit
  }

  //parent process
  while(1) { //infinite excution
	sleep(1); 
	printf("\nParent Not invoked Wait()!");
  }   
  
  /* parent will keep waiting without knowledge of child being made to exit. 
  as a result it still has an entry in the process table even though it has finished execution.
  This creates a resource leak.*/
  
  return 0;
}
