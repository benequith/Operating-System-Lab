/* creation of a process with fork()  
Understand separate memory space using fork()*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
   pid_t pid;
   int vble = 101;
   printf("Before fork \n");
   
   pid = fork(); /* replicates current process 
				On  success, the PID of the child process is returned in the parent, 
				and 0 is returned in the child.  
				On failure, -1 is returned in the parent, no child process is created, 
				and errno is set appropriately.*/
   
   printf("pid = %d, process_id = %d, parent_process_id = %d, variable value = %d \n", pid, getpid(), getppid(), ++vble);//exit(0);
   return 0;  
}


