/* creation of a process with fork()  
Understand existence of orphan process*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){  
	pid_t pid;
	if ((pid = fork()) > 0) { // parent process
      printf("I am Parent, my ID %d, I have child with ID: %d, My ParentID = %d\n\n", getpid(), pid, getppid()); 
      exit(10);
   } 
   
   else if (pid == 0) { // child process
     printf("I am Child, my ID %d, MY PARENT ID = %d\n\n",getpid(),getppid()); //getppid() reports different 
     sleep(4); // child is waiting for some time. by this time parent process finishes
     printf("I am Child, my ID %d, MY PARENT ID = %d\n\n",getpid(),getppid());//getppid() reports different 
     exit(0);
   }
   
   else printf("Problem in child creation....\n");
}